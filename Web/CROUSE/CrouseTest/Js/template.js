/**************************************************************************************************
 * Copyright ©  14:41 2021 -4 -19  殇璃墨 All rights reserved.                                       *
 *    Licensed under the Apache License, Version 2.0 (the "License");                             *
 *    you may not use this file except in compliance with the License.                            *
 *    You may obtain a copy of the License at                                                     *
 *                                                                                                *
 *      http://www.apache.org/licenses/LICENSE-2.0                                                *
 *                                                                                                *
 *    Unless required by applicable law or agreed to in writing, software                         *
 *    distributed under the License is distributed on an "AS IS" BASIS,                           *
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                    *
 *    See the License for the specific language governing permissions and                         *
 *    limitations under the License.                                                              *
 * Love 殇璃雪 Forever!                                                                              *
 *                                                                                                *
 **************************************************************************************************/

var sum= 10
for (var i=0; i<100;i++){
    sum +=i;
}
document.write("1-100的和为："+sum+"<br>")
// 反转字符串函数
function reverse(s) {
    var sum= 0
    for (var i=0; i<s;i++){
        sum +=i;
    }
    return sum;
}

// 配置按钮回调函数
function revbtn() {
    var s = in1.value;
    ou1.innerText = reverse(s);		// 直接通过id获得对象
}

// 清除按钮
function clrbtn() {
    in1.value = null;				// 
    in1.innerText = null;			// 直接通过id获得对象
    ou1.innerText = null;			// 
}



var source=document.getElementById(("source"));
{
    EventTarget.dataTransfer.setData("text","Hello,World!2333333333333")
}
