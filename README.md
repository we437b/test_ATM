# test_ATM
Bear Robotics Korea Coding Test(ATM task)

### Functions
1. PIN LOGIN/출금(withdrawal)/입금(deposit) 기능이 완성되어 있습니다.
2. 파일에 기록되는 형식으로 실제 은행 서버와의 연결을 simulate 해보았습니다.

### Instructions for Cloning(클론 방법 안내)
1. Please clone into a UNIX server through git clone command
https://github.com/we437b/test_ATM.git is the address of this repository.
2. make the required object files through "g++ -c user.h user.cpp" and "g++ -c driver.cpp"
3. make the executable file with "g++ -o driver.o user.o" command, and run ./a.out to test the file.


1. git clone 커맨드를 이용하여 UNIX서버에 클론하여 주십시오
이 git의 주소는 https://github.com/we437b/test_ATM.git 입니다!
2. "g++ -c user.h user.cpp" 로 user.o와 "g++ -c driver.cpp" 를 통해 driver.o파일을 생성해주시고,
3. "g++ -o driver.o user.o"를 통해 executable 파일을 생성하여 ./a.out을 통해 테스트해주십시오.

### Instructions for Testing(테스트 안내)
1. once entering the program, input a card number(the second entry in line of USER_INFO.INFO) chosen from a file.
2. input the PIN of that card, which is the last entry in line of USER_INFO.INFO 
3. You can then use the functions listed by entering the number of the functions (for example, "1" for checking balance)

1. 프로그램에 들어가시면, 카드 번호 (USER_INFO.INFO 에서 줄에서 두 번째 단어로 입력된 숫자) 를 골라 사용하실 수 있습니다.
2. 그 카드의 PIN(해당 줄의 마지막 단어로 입력된 4자리 숫자) 를 이용해 로그인하시면 기능들을 사용하실 수 있습니다.
3. 기능을 사용하기 위해선 각 기능의 안내에 알맞은 숫자를 눌러주십시오(예시로, 1번을 누르면 잔액 확인이 가능합니다)

#### for your convenience, this is an example of the data you could use(사용하실 수 있는 사용자 정보 예시)
Card(카드번호): 4485796507596996
PIN: 9562 



