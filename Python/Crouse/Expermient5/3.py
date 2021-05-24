# -*-coding:UTF-8-*-
import json
try:
    with open("./nameusers.json", "r") as fp:
        data = json.loads(fp.read())
        print("Found and PrintValues!")
except FileNotFoundError:
    print("Not Found File")
    print("Create a new file named 'data.json'")
    data = input("Please enter user name:")
    with open("nameusers.json" , "w") as fp2:
        fp2.write(json.dumps(data))
    print("We have remembered your data。")
else:
    print("Welcome back!" + data)
