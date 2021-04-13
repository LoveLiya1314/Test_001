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

import time
scale=10
print("------START--------")
for i in range(scale+1):
    a,b='**'*i,'..'*(scale-i)
    c=(i/scale)*100
    print("{:^3.0f}%[{}->{}]".format(c,a,b))
    time.sleep(0.1)
print("-------END----------")

scale=100

print("------START--------")
for i in range(scale+1):
   # a,b='**'*i,'..'*(scale-i)
    c=(i/scale)*100
    print("{:.0f}%".format(c))
    time.sleep(0.03)
print()
print("-------END----------")


scale=100

print("------START--------")
for i in range(scale+1):
   # a,b='**'*i,'..'*(scale-i)
    c=(i/scale)*100
    print("{:.0f}% ".format(c),end=" ")
    time.sleep(0.01)
print()
print("-------END----------")

