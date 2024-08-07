# 포인터 멤버 접근 연산자 (->)

포인터 멤버 접근 연산자는 구조체 인스턴스의 주소값을 갖고있는 포인터변수가 인스턴스를 역참조할때
쓰이는 연산자가 에로우 연산자(->) 라고한다.

아래와 같은 구조체가 있다고 가정해보자
```c
typedef struct {
    char name[30];
    int age;
}User;
```

위 구조체는 본적으로 인스턴스를 선언 후 .(dot 연산자) 를 통해 멤버 변수에 접근이 가능하다.
```c
    User user; // user 인스턴스 생성
    // dot 연산으로 멤버 변수 접근
    strcpy(user.name, 'JSH');
    user.age = 24;
```

이를 포인터를 사용하여 아래와 같이 접근도 가능하다.
```c
    User user; // user 인스턴스 생성
    User* puser = &user; // user 인스턴스의 주소값을 포인터 변수에 넘겨준다.
    // arrow 연산으로 접근
    strcpy(puser->user, 'JSH');
    puser->age = 24;

```

인스턴스 포인터를 직접적으로 .(dot 연산자)를 통해 멤버변수에 접근을 허용하지 않지만
역참조 후 .(dot 연산자) 를 통한 접근은 가능하다
그러나 직관적이지 않아 ->(arrow 연산자)를 통해 접근하는 것을 권장한다.
예시는 아래와 같다
```c
    User user; // user 인스턴스 생성
    User* puser = &user; // user 인스턴스의 주소값을 포인터 변수에 넘겨준다.
    // 역참조 후 .(dot 연산자로 접근, 권장되진 않음)
    strcpy((*puser).user, 'JSH');
    (*puser).age = 24;

    // 아래와 같은 접근은 허용하지 않음
    strcpy(puser.user, 'JSH');
    puser.age = 24;

```
