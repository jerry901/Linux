<buffering>
$ gcc buffer.c
$ a.out /etc/passwd
스트림 = /etc/passwd, 완전 버퍼 사용
$ a.out stdin
한 글자 입력:x
스트림 = stdin, 줄 버퍼 사용
$ a.out stdout
스트림 = stdout, 줄 버퍼 사용
$ a.out stderr
스트림 = stderr, 버퍼 미사용

[buffer_Linux.c on kws0.kangnam.ac.kr
 - id:unix101~unix103
 - pwd:unix101~unix103]
$ gcc buffer_Linux.c
$ a.out a.out
스트림 = a.out, 완전 버퍼 사용, 버퍼 크기 = 4096
$ a.out stdin
한 글자 입력:x
스트림 = stdin, 줄 버퍼 사용, 버퍼 크기 = 1024
$ a.out stderr
스트림 = stderr, 버퍼 미사용, 버퍼 크기 = 0

<setbuf()>
$ gcc setbuf.c
$ a.out
안녕하세요, 리눅스입니다!  <-- buffered, '\n' triggers standard output.
여러분, 반갑습니다 ^^  <-- unbuffered, printed immediately 

<setvbuf(fp, buf, mode, size)>
$ gcc setvbuf.c
$ a.out
첫 번째 스트림: 1024 바이트 크기 버퍼 사용
두 번째 스트림: 버퍼 미사용

