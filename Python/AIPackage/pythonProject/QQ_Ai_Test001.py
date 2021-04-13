# ##################################################################################################
#  Copyright ©  17:54 2021 -4 -13  Lambert All rights reserved.                                    #
#     Licensed under the Apache License, Version 2.0 (the "License");                              #
#     you may not use this file except in compliance with the License.                             #
#     You may obtain a copy of the License at                                                      #
#                                                                                                  #
#       http://www.apache.org/licenses/LICENSE-2.0                                                 #
#                                                                                                  #
#     Unless required by applicable law or agreed to in writing, software                          #
#     distributed under the License is distributed on an "AS IS" BASIS,                            #
#     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                     #
#     See the License for the specific language governing permissions and                          #
#     limitations under the License.                                                               #
#  Love Liya Forever!                                                                              #
# ##################################################################################################

import _thread
import json
import logging
import os
import re
import socket
import sys
import time
import tkinter

import flask
import win32clipboard
import win32con
import win32gui

server = flask.Flask(__name__)  # 创建1个Flask实例
ui_title = "智恒达自动发送程序"
qq_group_1 = "***群"
qq_group_2 = "####群"
reg1 = re.compile(r'(.*)银行(.*)520520')
reg2 = re.compile(r'(.*)银行(.*)748748')
# 处理日志,每次启动都会刷新
if not os.path.isdir(r'E:\py_log'):
    os.makedirs(r'E:\py_log')
logging.basicConfig(filename='E:\py_log\pyexe.log', filemode="w", level=logging.INFO)


# sendmsg接口
@server.route('/qq/sendmsg', methods=['post'])
def sendmsg_2_qq():
    logging.info(">>>")
    now = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    logging.info(f">>>{now}")
    msginfo = flask.request.get_data()  # 前台application/json
    msgcontent = json.loads(msginfo).get('msginfo')
    logging.info(f">>>接收到的消息为:{msgcontent}")
    if msginfo is None:
        msgcontent = "空"
    if reg1.match(msgcontent) is not None:
        result = send_msg(msgcontent, qq_group_1)
    elif reg2.match(msgcontent) is not None:
        result = send_msg(msgcontent, qq_group_2)
    else:
        result = "短信内容不匹配,无法发送"
    # 处理结果
    res = {
        'msg': None,
        'msg_code': None}
    if result == "":
        res['msg'] = "处理成功"
        res['msg_code'] = 0
    else:
        res['msg'] = result
        res['msg_code'] = 1
    logging.info(f">>>{res}")
    return json.dumps(res, ensure_ascii=False)


# 获取本机ip
def get_host_ip():
    sok = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        sok.connect(('8.8.8.8', 80))
        ip = sok.getsockname()[0]
    finally:
        sok.close()
    return ip


# 获取窗口并发送消息 0成功 1失败
def send_msg(sendmsg, winname):
    qqhd = win32gui.FindWindow("TXGuiFoundation", winname)
    rt_msg = ""
    if qqhd == 0:
        rt_msg = f"找不到{winname}窗口,无法发送"
    else:
        try:
            if win32gui.IsIconic(qqhd):
                logging.info(">>>窗口已经最小化了")
                win32gui.ShowWindow(qqhd, win32con.SW_SHOWNORMAL)
                time.sleep(0.1)
            logging.info(">>>开始虚拟按键操作")
            # 设置剪贴板
            win32clipboard.OpenClipboard()
            win32clipboard.EmptyClipboard()
            win32clipboard.SetClipboardData(win32con.CF_UNICODETEXT, sendmsg)
            win32clipboard.CloseClipboard()
            time.sleep(0.1)
            # 填充消息
            win32gui.PostMessage(qqhd, win32con.WM_CHAR, 22, 2080193)
            win32gui.PostMessage(qqhd, win32con.WM_PASTE, 0, 0)
            time.sleep(0.1)
            # 回车发送消息
            win32gui.PostMessage(qqhd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
            win32gui.PostMessage(qqhd, win32con.WM_KEYUP, win32con.VK_RETURN, 0)
            time.sleep(0.1)
            # 清空剪贴板
            win32clipboard.OpenClipboard()
            win32clipboard.EmptyClipboard()
            win32clipboard.CloseClipboard()
            time.sleep(0.5)
        except Exception as e:
            logging.info(f">>>出现异常:{e}")
            rt_msg = "程序异常"
    return rt_msg


# 校验
def check_wins():
    gp1hd = win32gui.FindWindow("TXGuiFoundation", qq_group_1)
    if gp1hd == 0:
        raise Exception(f"找不到{qq_group_1}窗口,无法启动")
    else:
        logging.info(f">>>>已找到{qq_group_1}窗口")
    gp2hd = win32gui.FindWindow("TXGuiFoundation", qq_group_2)
    if gp2hd == 0:
        raise Exception(f"找不到{qq_group_2}窗口,无法启动")
    else:
        logging.info(f">>>>已找到{qq_group_2}窗口")
    return 1


# 关闭tk窗口
def close_tk():
    tkhd = win32gui.FindWindow("TkTopLevel", ui_title)
    if tkhd == 0:
        raise Exception("找不到tk窗口,无法关闭")
        # 最小化
    win32gui.CloseWindow(tkhd)


# 启动flask服务器接收请求
def start_server():
    server.run(port=8008, host=get_host_ip(), threaded=False)


# 另开一个线程启动服务器
def create_thread(start_button):
    _thread.start_new_thread(start_server, ())
    time.sleep(1)
    start_button.config(state='disabled')
    close_exewin()
    close_tk()


# 关闭cmd.exe窗口,不存在也不会报错
def close_exewin():
    exename = str(sys.executable)
    logging.info(f">>>httpservice.exe窗口路径为:{exename}")
    exehd = win32gui.FindWindow("ConsoleWindowClass", exename)
    if exehd == 0:
        logging.info(">>>找不到exe窗口")
    else:
        win32gui.CloseWindow(exehd)


# 创建图像化界面
def create_ui(title):
    root = tkinter.Tk()     # 创建顶层窗口
    root.geometry('400x200')     # 初始化窗口大小
    root.title(title)   # 标题
    # 校验提示
    check_str = tkinter.StringVar(value='')
    error_label = tkinter.Label(root, textvariable=check_str, anchor='w', background='yellow', foreground='black')
    error_label.place(x=50, y=10, height=20)
    try:
        if check_wins() == 1:
            check_str.set("校验成功")
        # ip显示
        ip_str = tkinter.StringVar(value='')
        ip_str.set("本机ip为: " + get_host_ip())
        ip_label = tkinter.Label(root, textvariable=ip_str, anchor='w')
        ip_label.place(x=50, y=50, height=20)
        # 启动
        start_button = tkinter.Button(root, text='启动', command=lambda: create_thread(start_button))
        start_button.place(x=50, y=100, width=50, height=30)
    except Exception as e:
        logging.info(f">>>错误信息:{e}")
        check_str.set(e)
        error_label.config(background='red')
    root.mainloop()


# win10系统可能会失败,安全卫士可能会屏蔽虚拟操作
if __name__ == '__main__':
    create_ui(ui_title)

