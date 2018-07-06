from functools import reduce

data = [
    {
        "name": "나재은",
        "age": 25,
        "location": ["서울", "광진구", "구의동"]
    },
    {
        "name": "나소빈",
        "age": 27,
        "location": ["서울", "광진구", "구의동"]
    },
    {
        "name": "서병수",
        "age": 25,
        "location": ["경기도", "구리시", "무슨동"]
    },
    {
        "name": "백은지",
        "age": 24,
        "location": ["서울", "태릉입구", "어떤동"]
    },
    {
        "name": "홍길동",
        "age": 43,
        "location": ["신출귀몰", "몰라", "몰라요"]
    },
]


result = list(filter(lambda obj: obj["age"] < 30, data))

for key, obj in result: 
    print("name", obj["name"])
    print("age", obj["age"])
