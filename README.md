# Java

자바를 공부하는 레파지토리 ^>^

## Git tutorial

### 새 작업 시작하기!

새 작업 시작시에는, 항상 새 branch 따서 작업하고, push 해서 리뷰 받기

```bash
# 새 브랜치 따기 전엔, 항상 최신의 master를 다운받아와.
git checkout master  # master로 시점을 옮겨서
git fetch origin     # origin의 최신 내용을 다운받아
git pull

# 새 브랜치 만들어
git branch b1    # create a branch
git checkout b1  # b1을 가리켜라
# TIP: 이 두 명령어를 치기 존나 귀찮으니까. 
# git checkout -b b1 
# 이렇게 한 명령어로 해결 가능

# 작업하세요 (추가/변경/삭제)
vi file1.txt

git add file1.txt  # 내가 작업한 파일들을 stage 상태로 add 한다.

git commit  # stage 상태에 있는 변경사항들이 괜찮은것 같으니, commit 할겡

git log     # 내가 커밋한 것들이 보여
# 만약 내 현재 브랜치 말고, 다른 모든 브랜치의 log를 함께 보고싶으면
# git log --all
# 그리고, log를 graph 형태로 이쁘게 보고싶으면
# git log --graph
# 그 두개를 다 합치면
# git log --all -graph

git push origin b1   # 다른사람들에게 내 b1을 공개하겟다.

# b1에 대한 PR를 만들어서 리뷰 받자
# 리뷰 승인나면, merge 버튼 눌러서 master에 반영하자.
```

### 만약, 딴놈이 먼저 merge해서 충돌났으면?

github에서 내 PR을 merge하려고하면, conflict가 났다고, resolve 하나는 경고가 뜰거다.

어떻게 resolve 하냐면

```bash
# 다시 master 브랜치로 돌아가서, 최신 내용을 갱신받아.
git checkout master  # master로 시점을 옮겨서
git fetch origin     # origin의 최신 내용을 다운받아
git pull

git checkout b1      # 다시 내 브랜치로 컴백

git rebase master    # 내 branch를 똑 때서, 최신의 master로 rebase

# 만약 팀원이 이미 수정한 것과 conflict가 있을 경우, git이 에러를 낼겁니다. resolve 하라고,
# 충돌난 파일을 여세요.
vi file1.txt
# 적당히 충돌을 해결하세요. 니 꼴리는대로. 아니면 팀원이랑 상의해서.

# 충돌해결 후, rebase 재개
git add file1.txt        # 충돌 해결됏음을 git에게 알림
git rebase --continue    # rebase 재개

# 이렇게까지 하면, 내 b1 branch는 최신 master를 base로 다시 태어났음.
# 다시 태어난 branch를 github에 push 할 땐, 기존 old branch를 ignore 하고, push할수잇도록,
# -f (force)를 사용해줘야한다.
git push -f origin b1

# 이제 github PR 들가보면 merge 할수 잇을거다.
```
### local에서 merge 하는 법
```bash
#b1 branch가 있다고 치자
#머지하기 직전 상태에서 master branch 로 checkout한 후 git merge b1을 한다.
#git checkout b1
#git merge b1
#git -D branch
#old branch를 delete한다.
