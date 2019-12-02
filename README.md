# Kind Linuxy
2019 System Programming Team Project from Department of Software, Konkuk Univ.  
  
Team no.7  
Members :
>201513110 박소연 (Leader)  
>201811164 김소양  
>201811203 은정연  
>201811224 조혜진  
  
Final Report Link : https://docs.google.com/document/d/1u7hHgCMJYVonuF-kCmHLUyWks3qNMUh5c2nM_24Fwmc/edit  

### 주의사항
- 현재 kindLinuxy 3이 최종입니다.변경사항은 kindLinuxy2 에서 잘 실행되는 지 확인 후! kindLinuxy3 에다 옮기고 commit, push 하도록 합시다.
- ubuntu 실제 home 경로 :  
**c: \ 사용자 \ 컴퓨터이름 \ Appdata(숨김폴더) \ local \ packages \ CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc \ localstates \ rootfs(root경로) \ home \ 사용자이름**
- 깃에 있는 것을 ubuntu 실제 경로에 복붙했을 때 1~3분가량의 딜레이가 있을 수 있으니 당장 ubuntu에서 ls해서 안떠도 당황하지 마세요.
  ->ubuntu 껐다가 다시 실행 시는 바로 적용됩니다!
- 복붙했을 경우 permission이 기존 linux 파일과 다를 수도 있으므로, 해당 경로에서 **chmod a+rw [파일명]** 명령어를 입력해줍시다.
- 컴파일 하는 법 :  
**gcc -c [헤더파일을 제외한 모든 소스 파일]**     ( ===> 오브젝트 파일(.o) 생성됨 )   -> gcc -c *.c
**gcc -o [실행 파일 이름] [모든 오브젝트 파일]**   ( ===> 실행 파일 생성됨 ) -> gcc -o test1 *.o
