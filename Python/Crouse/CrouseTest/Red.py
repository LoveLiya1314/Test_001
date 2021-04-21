# -*-coding:UTF-8-*-
import random
def send_money(total_yuan, num):
    """send_money

    :param total_yuan: 元为单位，转成分
    :param num: 人数
    """
    total = total_yuan * 100  # 分为单位
    cur_total = 0
    for i in range(num - 1):
        remain = total - cur_total
        money = random.randint(1, int(remain / (num - i) * 2))
        cur_total += money
        yield round(money / 100.0, 2)
    yield round((total - cur_total) /100.0, 2)


def test():
    t = 0
    for i in send_money(100, 10):
        t += i
        print(i)
    print('sum:', t)


if __name__ == '__main__':
    test()