
./little_tommy:     file format elf32-i386


Disassembly of section .interp:

08048154 <.interp>:
 8048154:	2f                   	das    
 8048155:	6c                   	insb   (%dx),%es:(%edi)
 8048156:	69 62 2f 6c 64 2d 6c 	imul   $0x6c2d646c,0x2f(%edx),%esp
 804815d:	69 6e 75 78 2e 73 6f 	imul   $0x6f732e78,0x75(%esi),%ebp
 8048164:	2e 32 00             	xor    %cs:(%eax),%al

Disassembly of section .note.ABI-tag:

08048168 <.note.ABI-tag>:
 8048168:	04 00                	add    $0x0,%al
 804816a:	00 00                	add    %al,(%eax)
 804816c:	10 00                	adc    %al,(%eax)
 804816e:	00 00                	add    %al,(%eax)
 8048170:	01 00                	add    %eax,(%eax)
 8048172:	00 00                	add    %al,(%eax)
 8048174:	47                   	inc    %edi
 8048175:	4e                   	dec    %esi
 8048176:	55                   	push   %ebp
 8048177:	00 00                	add    %al,(%eax)
 8048179:	00 00                	add    %al,(%eax)
 804817b:	00 02                	add    %al,(%edx)
 804817d:	00 00                	add    %al,(%eax)
 804817f:	00 06                	add    %al,(%esi)
 8048181:	00 00                	add    %al,(%eax)
 8048183:	00 20                	add    %ah,(%eax)
 8048185:	00 00                	add    %al,(%eax)
	...

Disassembly of section .note.gnu.build-id:

08048188 <.note.gnu.build-id>:
 8048188:	04 00                	add    $0x0,%al
 804818a:	00 00                	add    %al,(%eax)
 804818c:	14 00                	adc    $0x0,%al
 804818e:	00 00                	add    %al,(%eax)
 8048190:	03 00                	add    (%eax),%eax
 8048192:	00 00                	add    %al,(%eax)
 8048194:	47                   	inc    %edi
 8048195:	4e                   	dec    %esi
 8048196:	55                   	push   %ebp
 8048197:	00 86 18 38 86 57    	add    %al,0x57863818(%esi)
 804819d:	26 f4                	es hlt 
 804819f:	8a a9 54 b8 df 92    	mov    -0x6d2047ac(%ecx),%ch
 80481a5:	0d 1b e3 ae 68       	or     $0x68aee31b,%eax
 80481aa:	3b                   	.byte 0x3b
 80481ab:	40                   	inc    %eax

Disassembly of section .gnu.hash:

080481ac <.gnu.hash>:
 80481ac:	02 00                	add    (%eax),%al
 80481ae:	00 00                	add    %al,(%eax)
 80481b0:	0d 00 00 00 01       	or     $0x1000000,%eax
 80481b5:	00 00                	add    %al,(%eax)
 80481b7:	00 05 00 00 00 80    	add    %al,0x80000000
 80481bd:	28 00                	sub    %al,(%eax)
 80481bf:	20 00                	and    %al,(%eax)
 80481c1:	00 00                	add    %al,(%eax)
 80481c3:	00 0d 00 00 00 ac    	add    %cl,0xac000000
 80481c9:	4b                   	dec    %ebx
 80481ca:	e3 c0                	jecxz  804818c <_init-0x268>
 80481cc:	67 55                	addr16 push %ebp
 80481ce:	61                   	popa   
 80481cf:	10                   	.byte 0x10

Disassembly of section .dynsym:

080481d0 <.dynsym>:
	...
 80481e0:	34 00                	xor    $0x0,%al
	...
 80481ea:	00 00                	add    %al,(%eax)
 80481ec:	12 00                	adc    (%eax),%al
 80481ee:	00 00                	add    %al,(%eax)
 80481f0:	70 00                	jo     80481f2 <_init-0x202>
	...
 80481fa:	00 00                	add    %al,(%eax)
 80481fc:	12 00                	adc    (%eax),%al
 80481fe:	00 00                	add    %al,(%eax)
 8048200:	2d 00 00 00 00       	sub    $0x0,%eax
 8048205:	00 00                	add    %al,(%eax)
 8048207:	00 00                	add    %al,(%eax)
 8048209:	00 00                	add    %al,(%eax)
 804820b:	00 12                	add    %dl,(%edx)
 804820d:	00 00                	add    %al,(%eax)
 804820f:	00 48 00             	add    %cl,0x0(%eax)
	...
 804821a:	00 00                	add    %al,(%eax)
 804821c:	12 00                	adc    (%eax),%al
 804821e:	00 00                	add    %al,(%eax)
 8048220:	3b 00                	cmp    (%eax),%eax
	...
 804822a:	00 00                	add    %al,(%eax)
 804822c:	12 00                	adc    (%eax),%al
 804822e:	00 00                	add    %al,(%eax)
 8048230:	50                   	push   %eax
	...
 8048239:	00 00                	add    %al,(%eax)
 804823b:	00 12                	add    %dl,(%edx)
 804823d:	00 00                	add    %al,(%eax)
 804823f:	00 22                	add    %ah,(%edx)
	...
 8048249:	00 00                	add    %al,(%eax)
 804824b:	00 12                	add    %dl,(%edx)
 804824d:	00 00                	add    %al,(%eax)
 804824f:	00 57 00             	add    %dl,0x0(%edi)
	...
 804825a:	00 00                	add    %al,(%eax)
 804825c:	12 00                	adc    (%eax),%al
 804825e:	00 00                	add    %al,(%eax)
 8048260:	75 00                	jne    8048262 <_init-0x192>
	...
 804826a:	00 00                	add    %al,(%eax)
 804826c:	20 00                	and    %al,(%eax)
 804826e:	00 00                	add    %al,(%eax)
 8048270:	41                   	inc    %ecx
	...
 8048279:	00 00                	add    %al,(%eax)
 804827b:	00 12                	add    %dl,(%edx)
 804827d:	00 00                	add    %al,(%eax)
 804827f:	00 5e 00             	add    %bl,0x0(%esi)
	...
 804828a:	00 00                	add    %al,(%eax)
 804828c:	12 00                	adc    (%eax),%al
 804828e:	00 00                	add    %al,(%eax)
 8048290:	1a 00                	sbb    (%eax),%al
	...
 804829a:	00 00                	add    %al,(%eax)
 804829c:	12 00                	adc    (%eax),%al
 804829e:	00 00                	add    %al,(%eax)
 80482a0:	0b 00                	or     (%eax),%eax
 80482a2:	00 00                	add    %al,(%eax)
 80482a4:	dc 89 04 08 04 00    	fmull  0x40804(%ecx)
 80482aa:	00 00                	add    %al,(%eax)
 80482ac:	11 00                	adc    %eax,(%eax)
 80482ae:	10 00                	adc    %al,(%eax)
 80482b0:	27                   	daa    
 80482b1:	00 00                	add    %al,(%eax)
 80482b3:	00 40 a0             	add    %al,-0x60(%eax)
 80482b6:	04 08                	add    $0x8,%al
 80482b8:	04 00                	add    $0x0,%al
 80482ba:	00 00                	add    %al,(%eax)
 80482bc:	11 00                	adc    %eax,(%eax)
 80482be:	1a 00                	sbb    (%eax),%al

Disassembly of section .dynstr:

080482c0 <.dynstr>:
 80482c0:	00 6c 69 62          	add    %ch,0x62(%ecx,%ebp,2)
 80482c4:	63 2e                	arpl   %bp,(%esi)
 80482c6:	73 6f                	jae    8048337 <_init-0xbd>
 80482c8:	2e 36 00 5f 49       	cs add %bl,%ss:0x49(%edi)
 80482cd:	4f                   	dec    %edi
 80482ce:	5f                   	pop    %edi
 80482cf:	73 74                	jae    8048345 <_init-0xaf>
 80482d1:	64 69 6e 5f 75 73 65 	imul   $0x64657375,%fs:0x5f(%esi),%ebp
 80482d8:	64 
 80482d9:	00 73 74             	add    %dh,0x74(%ebx)
 80482dc:	72 6e                	jb     804834c <_init-0xa8>
 80482de:	63 70 79             	arpl   %si,0x79(%eax)
 80482e1:	00 70 75             	add    %dh,0x75(%eax)
 80482e4:	74 73                	je     8048359 <_init-0x9b>
 80482e6:	00 73 74             	add    %dh,0x74(%ebx)
 80482e9:	64 69 6e 00 73 74 72 	imul   $0x64727473,%fs:0x0(%esi),%ebp
 80482f0:	64 
 80482f1:	75 70                	jne    8048363 <_init-0x91>
 80482f3:	00 70 72             	add    %dh,0x72(%eax)
 80482f6:	69 6e 74 66 00 66 67 	imul   $0x67660066,0x74(%esi),%ebp
 80482fd:	65 74 73             	gs je  8048373 <_init-0x81>
 8048300:	00 73 74             	add    %dh,0x74(%ebx)
 8048303:	72 6c                	jb     8048371 <_init-0x83>
 8048305:	65 6e                	outsb  %gs:(%esi),(%dx)
 8048307:	00 67 65             	add    %ah,0x65(%edi)
 804830a:	74 63                	je     804836f <_init-0x85>
 804830c:	68 61 72 00 6d       	push   $0x6d007261
 8048311:	61                   	popa   
 8048312:	6c                   	insb   (%dx),%es:(%edi)
 8048313:	6c                   	insb   (%dx),%es:(%edi)
 8048314:	6f                   	outsl  %ds:(%esi),(%dx)
 8048315:	63 00                	arpl   %ax,(%eax)
 8048317:	73 79                	jae    8048392 <_init-0x62>
 8048319:	73 74                	jae    804838f <_init-0x65>
 804831b:	65 6d                	gs insl (%dx),%es:(%edi)
 804831d:	00 5f 5f             	add    %bl,0x5f(%edi)
 8048320:	6c                   	insb   (%dx),%es:(%edi)
 8048321:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%edx),%esp
 8048328:	72 74                	jb     804839e <_init-0x56>
 804832a:	5f                   	pop    %edi
 804832b:	6d                   	insl   (%dx),%es:(%edi)
 804832c:	61                   	popa   
 804832d:	69 6e 00 66 72 65 65 	imul   $0x65657266,0x0(%esi),%ebp
 8048334:	00 5f 5f             	add    %bl,0x5f(%edi)
 8048337:	67 6d                	insl   (%dx),%es:(%di)
 8048339:	6f                   	outsl  %ds:(%esi),(%dx)
 804833a:	6e                   	outsb  %ds:(%esi),(%dx)
 804833b:	5f                   	pop    %edi
 804833c:	73 74                	jae    80483b2 <_init-0x42>
 804833e:	61                   	popa   
 804833f:	72 74                	jb     80483b5 <_init-0x3f>
 8048341:	5f                   	pop    %edi
 8048342:	5f                   	pop    %edi
 8048343:	00 47 4c             	add    %al,0x4c(%edi)
 8048346:	49                   	dec    %ecx
 8048347:	42                   	inc    %edx
 8048348:	43                   	inc    %ebx
 8048349:	5f                   	pop    %edi
 804834a:	32 2e                	xor    (%esi),%ch
 804834c:	30 00                	xor    %al,(%eax)

Disassembly of section .gnu.version:

0804834e <.gnu.version>:
 804834e:	00 00                	add    %al,(%eax)
 8048350:	02 00                	add    (%eax),%al
 8048352:	02 00                	add    (%eax),%al
 8048354:	02 00                	add    (%eax),%al
 8048356:	02 00                	add    (%eax),%al
 8048358:	02 00                	add    (%eax),%al
 804835a:	02 00                	add    (%eax),%al
 804835c:	02 00                	add    (%eax),%al
 804835e:	02 00                	add    (%eax),%al
 8048360:	00 00                	add    %al,(%eax)
 8048362:	02 00                	add    (%eax),%al
 8048364:	02 00                	add    (%eax),%al
 8048366:	02 00                	add    (%eax),%al
 8048368:	01 00                	add    %eax,(%eax)
 804836a:	02 00                	add    (%eax),%al

Disassembly of section .gnu.version_r:

0804836c <.gnu.version_r>:
 804836c:	01 00                	add    %eax,(%eax)
 804836e:	01 00                	add    %eax,(%eax)
 8048370:	01 00                	add    %eax,(%eax)
 8048372:	00 00                	add    %al,(%eax)
 8048374:	10 00                	adc    %al,(%eax)
 8048376:	00 00                	add    %al,(%eax)
 8048378:	00 00                	add    %al,(%eax)
 804837a:	00 00                	add    %al,(%eax)
 804837c:	10 69 69             	adc    %ch,0x69(%ecx)
 804837f:	0d 00 00 02 00       	or     $0x20000,%eax
 8048384:	84 00                	test   %al,(%eax)
 8048386:	00 00                	add    %al,(%eax)
 8048388:	00 00                	add    %al,(%eax)
	...

Disassembly of section .rel.dyn:

0804838c <.rel.dyn>:
 804838c:	fc                   	cld    
 804838d:	9f                   	lahf   
 804838e:	04 08                	add    $0x8,%al
 8048390:	06                   	push   %es
 8048391:	09 00                	or     %eax,(%eax)
 8048393:	00 40 a0             	add    %al,-0x60(%eax)
 8048396:	04 08                	add    $0x8,%al
 8048398:	05                   	.byte 0x5
 8048399:	0e                   	push   %cs
	...

Disassembly of section .rel.plt:

0804839c <.rel.plt>:
 804839c:	0c a0                	or     $0xa0,%al
 804839e:	04 08                	add    $0x8,%al
 80483a0:	07                   	pop    %es
 80483a1:	01 00                	add    %eax,(%eax)
 80483a3:	00 10                	add    %dl,(%eax)
 80483a5:	a0 04 08 07 02       	mov    0x2070804,%al
 80483aa:	00 00                	add    %al,(%eax)
 80483ac:	14 a0                	adc    $0xa0,%al
 80483ae:	04 08                	add    $0x8,%al
 80483b0:	07                   	pop    %es
 80483b1:	03 00                	add    (%eax),%eax
 80483b3:	00 18                	add    %bl,(%eax)
 80483b5:	a0 04 08 07 04       	mov    0x4070804,%al
 80483ba:	00 00                	add    %al,(%eax)
 80483bc:	1c a0                	sbb    $0xa0,%al
 80483be:	04 08                	add    $0x8,%al
 80483c0:	07                   	pop    %es
 80483c1:	05 00 00 20 a0       	add    $0xa0200000,%eax
 80483c6:	04 08                	add    $0x8,%al
 80483c8:	07                   	pop    %es
 80483c9:	06                   	push   %es
 80483ca:	00 00                	add    %al,(%eax)
 80483cc:	24 a0                	and    $0xa0,%al
 80483ce:	04 08                	add    $0x8,%al
 80483d0:	07                   	pop    %es
 80483d1:	07                   	pop    %es
 80483d2:	00 00                	add    %al,(%eax)
 80483d4:	28 a0 04 08 07 08    	sub    %ah,0x8070804(%eax)
 80483da:	00 00                	add    %al,(%eax)
 80483dc:	2c a0                	sub    $0xa0,%al
 80483de:	04 08                	add    $0x8,%al
 80483e0:	07                   	pop    %es
 80483e1:	0a 00                	or     (%eax),%al
 80483e3:	00 30                	add    %dh,(%eax)
 80483e5:	a0 04 08 07 0b       	mov    0xb070804,%al
 80483ea:	00 00                	add    %al,(%eax)
 80483ec:	34 a0                	xor    $0xa0,%al
 80483ee:	04 08                	add    $0x8,%al
 80483f0:	07                   	pop    %es
 80483f1:	0c 00                	or     $0x0,%al
	...

Disassembly of section .init:

080483f4 <_init>:
 80483f4:	53                   	push   %ebx
 80483f5:	83 ec 08             	sub    $0x8,%esp
 80483f8:	e8 23 01 00 00       	call   8048520 <__x86.get_pc_thunk.bx>
 80483fd:	81 c3 03 1c 00 00    	add    $0x1c03,%ebx
 8048403:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 8048409:	85 c0                	test   %eax,%eax
 804840b:	74 05                	je     8048412 <_init+0x1e>
 804840d:	e8 ce 00 00 00       	call   80484e0 <__gmon_start__@plt>
 8048412:	83 c4 08             	add    $0x8,%esp
 8048415:	5b                   	pop    %ebx
 8048416:	c3                   	ret    

Disassembly of section .plt:

08048420 <.plt>:
 8048420:	ff 35 04 a0 04 08    	pushl  0x804a004
 8048426:	ff 25 08 a0 04 08    	jmp    *0x804a008
 804842c:	00 00                	add    %al,(%eax)
	...

08048430 <printf@plt>:
 8048430:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 8048436:	68 00 00 00 00       	push   $0x0
 804843b:	e9 e0 ff ff ff       	jmp    8048420 <.plt>

08048440 <free@plt>:
 8048440:	ff 25 10 a0 04 08    	jmp    *0x804a010
 8048446:	68 08 00 00 00       	push   $0x8
 804844b:	e9 d0 ff ff ff       	jmp    8048420 <.plt>

08048450 <strdup@plt>:
 8048450:	ff 25 14 a0 04 08    	jmp    *0x804a014
 8048456:	68 10 00 00 00       	push   $0x10
 804845b:	e9 c0 ff ff ff       	jmp    8048420 <.plt>

08048460 <getchar@plt>:
 8048460:	ff 25 18 a0 04 08    	jmp    *0x804a018
 8048466:	68 18 00 00 00       	push   $0x18
 804846b:	e9 b0 ff ff ff       	jmp    8048420 <.plt>

08048470 <fgets@plt>:
 8048470:	ff 25 1c a0 04 08    	jmp    *0x804a01c
 8048476:	68 20 00 00 00       	push   $0x20
 804847b:	e9 a0 ff ff ff       	jmp    8048420 <.plt>

08048480 <malloc@plt>:
 8048480:	ff 25 20 a0 04 08    	jmp    *0x804a020
 8048486:	68 28 00 00 00       	push   $0x28
 804848b:	e9 90 ff ff ff       	jmp    8048420 <.plt>

08048490 <puts@plt>:
 8048490:	ff 25 24 a0 04 08    	jmp    *0x804a024
 8048496:	68 30 00 00 00       	push   $0x30
 804849b:	e9 80 ff ff ff       	jmp    8048420 <.plt>

080484a0 <system@plt>:
 80484a0:	ff 25 28 a0 04 08    	jmp    *0x804a028
 80484a6:	68 38 00 00 00       	push   $0x38
 80484ab:	e9 70 ff ff ff       	jmp    8048420 <.plt>

080484b0 <strlen@plt>:
 80484b0:	ff 25 2c a0 04 08    	jmp    *0x804a02c
 80484b6:	68 40 00 00 00       	push   $0x40
 80484bb:	e9 60 ff ff ff       	jmp    8048420 <.plt>

080484c0 <__libc_start_main@plt>:
 80484c0:	ff 25 30 a0 04 08    	jmp    *0x804a030
 80484c6:	68 48 00 00 00       	push   $0x48
 80484cb:	e9 50 ff ff ff       	jmp    8048420 <.plt>

080484d0 <strncpy@plt>:
 80484d0:	ff 25 34 a0 04 08    	jmp    *0x804a034
 80484d6:	68 50 00 00 00       	push   $0x50
 80484db:	e9 40 ff ff ff       	jmp    8048420 <.plt>

Disassembly of section .plt.got:

080484e0 <__gmon_start__@plt>:
 80484e0:	ff 25 fc 9f 04 08    	jmp    *0x8049ffc
 80484e6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

080484f0 <_start>:
 80484f0:	31 ed                	xor    %ebp,%ebp
 80484f2:	5e                   	pop    %esi
 80484f3:	89 e1                	mov    %esp,%ecx
 80484f5:	83 e4 f0             	and    $0xfffffff0,%esp
 80484f8:	50                   	push   %eax
 80484f9:	54                   	push   %esp
 80484fa:	52                   	push   %edx
 80484fb:	68 c0 89 04 08       	push   $0x80489c0
 8048500:	68 60 89 04 08       	push   $0x8048960
 8048505:	51                   	push   %ecx
 8048506:	56                   	push   %esi
 8048507:	68 5c 86 04 08       	push   $0x804865c
 804850c:	e8 af ff ff ff       	call   80484c0 <__libc_start_main@plt>
 8048511:	f4                   	hlt    
 8048512:	66 90                	xchg   %ax,%ax
 8048514:	66 90                	xchg   %ax,%ax
 8048516:	66 90                	xchg   %ax,%ax
 8048518:	66 90                	xchg   %ax,%ax
 804851a:	66 90                	xchg   %ax,%ax
 804851c:	66 90                	xchg   %ax,%ax
 804851e:	66 90                	xchg   %ax,%ax

08048520 <__x86.get_pc_thunk.bx>:
 8048520:	8b 1c 24             	mov    (%esp),%ebx
 8048523:	c3                   	ret    
 8048524:	66 90                	xchg   %ax,%ax
 8048526:	66 90                	xchg   %ax,%ax
 8048528:	66 90                	xchg   %ax,%ax
 804852a:	66 90                	xchg   %ax,%ax
 804852c:	66 90                	xchg   %ax,%ax
 804852e:	66 90                	xchg   %ax,%ax

08048530 <deregister_tm_clones>:
 8048530:	b8 43 a0 04 08       	mov    $0x804a043,%eax
 8048535:	2d 40 a0 04 08       	sub    $0x804a040,%eax
 804853a:	83 f8 06             	cmp    $0x6,%eax
 804853d:	76 1a                	jbe    8048559 <deregister_tm_clones+0x29>
 804853f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048544:	85 c0                	test   %eax,%eax
 8048546:	74 11                	je     8048559 <deregister_tm_clones+0x29>
 8048548:	55                   	push   %ebp
 8048549:	89 e5                	mov    %esp,%ebp
 804854b:	83 ec 14             	sub    $0x14,%esp
 804854e:	68 40 a0 04 08       	push   $0x804a040
 8048553:	ff d0                	call   *%eax
 8048555:	83 c4 10             	add    $0x10,%esp
 8048558:	c9                   	leave  
 8048559:	f3 c3                	repz ret 
 804855b:	90                   	nop
 804855c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

08048560 <register_tm_clones>:
 8048560:	b8 40 a0 04 08       	mov    $0x804a040,%eax
 8048565:	2d 40 a0 04 08       	sub    $0x804a040,%eax
 804856a:	c1 f8 02             	sar    $0x2,%eax
 804856d:	89 c2                	mov    %eax,%edx
 804856f:	c1 ea 1f             	shr    $0x1f,%edx
 8048572:	01 d0                	add    %edx,%eax
 8048574:	d1 f8                	sar    %eax
 8048576:	74 1b                	je     8048593 <register_tm_clones+0x33>
 8048578:	ba 00 00 00 00       	mov    $0x0,%edx
 804857d:	85 d2                	test   %edx,%edx
 804857f:	74 12                	je     8048593 <register_tm_clones+0x33>
 8048581:	55                   	push   %ebp
 8048582:	89 e5                	mov    %esp,%ebp
 8048584:	83 ec 10             	sub    $0x10,%esp
 8048587:	50                   	push   %eax
 8048588:	68 40 a0 04 08       	push   $0x804a040
 804858d:	ff d2                	call   *%edx
 804858f:	83 c4 10             	add    $0x10,%esp
 8048592:	c9                   	leave  
 8048593:	f3 c3                	repz ret 
 8048595:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048599:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080485a0 <__do_global_dtors_aux>:
 80485a0:	80 3d 44 a0 04 08 00 	cmpb   $0x0,0x804a044
 80485a7:	75 13                	jne    80485bc <__do_global_dtors_aux+0x1c>
 80485a9:	55                   	push   %ebp
 80485aa:	89 e5                	mov    %esp,%ebp
 80485ac:	83 ec 08             	sub    $0x8,%esp
 80485af:	e8 7c ff ff ff       	call   8048530 <deregister_tm_clones>
 80485b4:	c6 05 44 a0 04 08 01 	movb   $0x1,0x804a044
 80485bb:	c9                   	leave  
 80485bc:	f3 c3                	repz ret 
 80485be:	66 90                	xchg   %ax,%ax

080485c0 <frame_dummy>:
 80485c0:	b8 10 9f 04 08       	mov    $0x8049f10,%eax
 80485c5:	8b 10                	mov    (%eax),%edx
 80485c7:	85 d2                	test   %edx,%edx
 80485c9:	75 05                	jne    80485d0 <frame_dummy+0x10>
 80485cb:	eb 93                	jmp    8048560 <register_tm_clones>
 80485cd:	8d 76 00             	lea    0x0(%esi),%esi
 80485d0:	ba 00 00 00 00       	mov    $0x0,%edx
 80485d5:	85 d2                	test   %edx,%edx
 80485d7:	74 f2                	je     80485cb <frame_dummy+0xb>
 80485d9:	55                   	push   %ebp
 80485da:	89 e5                	mov    %esp,%ebp
 80485dc:	83 ec 14             	sub    $0x14,%esp
 80485df:	50                   	push   %eax
 80485e0:	ff d2                	call   *%edx
 80485e2:	83 c4 10             	add    $0x10,%esp
 80485e5:	c9                   	leave  
 80485e6:	e9 75 ff ff ff       	jmp    8048560 <register_tm_clones>

080485eb <read_s>:
 80485eb:	55                   	push   %ebp
 80485ec:	89 e5                	mov    %esp,%ebp
 80485ee:	83 ec 18             	sub    $0x18,%esp
 80485f1:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 80485f8:	eb 16                	jmp    8048610 <read_s+0x25>
 80485fa:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80485fd:	8d 50 01             	lea    0x1(%eax),%edx
 8048600:	89 55 f4             	mov    %edx,-0xc(%ebp)
 8048603:	89 c2                	mov    %eax,%edx
 8048605:	8b 45 08             	mov    0x8(%ebp),%eax
 8048608:	01 c2                	add    %eax,%edx
 804860a:	0f b6 45 f3          	movzbl -0xd(%ebp),%eax
 804860e:	88 02                	mov    %al,(%edx)
 8048610:	e8 4b fe ff ff       	call   8048460 <getchar@plt>
 8048615:	88 45 f3             	mov    %al,-0xd(%ebp)
 8048618:	80 7d f3 0a          	cmpb   $0xa,-0xd(%ebp)
 804861c:	74 11                	je     804862f <read_s+0x44>
 804861e:	80 7d f3 ff          	cmpb   $0xff,-0xd(%ebp)
 8048622:	74 0b                	je     804862f <read_s+0x44>
 8048624:	8b 45 0c             	mov    0xc(%ebp),%eax
 8048627:	83 e8 01             	sub    $0x1,%eax
 804862a:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 804862d:	7f cb                	jg     80485fa <read_s+0xf>
 804862f:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048632:	8b 45 08             	mov    0x8(%ebp),%eax
 8048635:	01 d0                	add    %edx,%eax
 8048637:	c6 00 00             	movb   $0x0,(%eax)
 804863a:	8b 45 0c             	mov    0xc(%ebp),%eax
 804863d:	83 e8 01             	sub    $0x1,%eax
 8048640:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 8048643:	75 14                	jne    8048659 <read_s+0x6e>
 8048645:	e8 16 fe ff ff       	call   8048460 <getchar@plt>
 804864a:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804864d:	83 7d f4 0a          	cmpl   $0xa,-0xc(%ebp)
 8048651:	74 06                	je     8048659 <read_s+0x6e>
 8048653:	83 7d f4 ff          	cmpl   $0xffffffff,-0xc(%ebp)
 8048657:	75 ec                	jne    8048645 <read_s+0x5a>
 8048659:	90                   	nop
 804865a:	c9                   	leave  
 804865b:	c3                   	ret    

0804865c <main>:
 804865c:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 8048660:	83 e4 f0             	and    $0xfffffff0,%esp
 8048663:	ff 71 fc             	pushl  -0x4(%ecx)
 8048666:	55                   	push   %ebp
 8048667:	89 e5                	mov    %esp,%ebp
 8048669:	53                   	push   %ebx
 804866a:	51                   	push   %ecx
 804866b:	81 ec 10 01 00 00    	sub    $0x110,%esp
 8048671:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8048677:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804867a:	31 c0                	xor    %eax,%eax
 804867c:	83 ec 0c             	sub    $0xc,%esp
 804867f:	68 e0 89 04 08       	push   $0x80489e0
 8048684:	e8 07 fe ff ff       	call   8048490 <puts@plt>
 8048689:	83 c4 10             	add    $0x10,%esp
 804868c:	c6 85 ed fe ff ff 00 	movb   $0x0,-0x113(%ebp)
 8048693:	83 ec 0c             	sub    $0xc,%esp
 8048696:	68 4c 8a 04 08       	push   $0x8048a4c
 804869b:	e8 90 fd ff ff       	call   8048430 <printf@plt>
 80486a0:	83 c4 10             	add    $0x10,%esp
 80486a3:	e8 b8 fd ff ff       	call   8048460 <getchar@plt>
 80486a8:	88 85 ee fe ff ff    	mov    %al,-0x112(%ebp)
 80486ae:	90                   	nop
 80486af:	e8 ac fd ff ff       	call   8048460 <getchar@plt>
 80486b4:	88 85 ef fe ff ff    	mov    %al,-0x111(%ebp)
 80486ba:	80 bd ef fe ff ff 0a 	cmpb   $0xa,-0x111(%ebp)
 80486c1:	74 09                	je     80486cc <main+0x70>
 80486c3:	80 bd ef fe ff ff ff 	cmpb   $0xff,-0x111(%ebp)
 80486ca:	75 e3                	jne    80486af <main+0x53>
 80486cc:	0f be 85 ee fe ff ff 	movsbl -0x112(%ebp),%eax
 80486d3:	83 e8 31             	sub    $0x31,%eax
 80486d6:	83 f8 04             	cmp    $0x4,%eax
 80486d9:	77 b8                	ja     8048693 <main+0x37>
 80486db:	8b 04 85 0c 8c 04 08 	mov    0x8048c0c(,%eax,4),%eax
 80486e2:	ff e0                	jmp    *%eax
 80486e4:	83 ec 0c             	sub    $0xc,%esp
 80486e7:	6a 48                	push   $0x48
 80486e9:	e8 92 fd ff ff       	call   8048480 <malloc@plt>
 80486ee:	83 c4 10             	add    $0x10,%esp
 80486f1:	a3 48 a0 04 08       	mov    %eax,0x804a048
 80486f6:	83 ec 0c             	sub    $0xc,%esp
 80486f9:	68 c2 8a 04 08       	push   $0x8048ac2
 80486fe:	e8 2d fd ff ff       	call   8048430 <printf@plt>
 8048703:	83 c4 10             	add    $0x10,%esp
 8048706:	a1 40 a0 04 08       	mov    0x804a040,%eax
 804870b:	83 ec 04             	sub    $0x4,%esp
 804870e:	50                   	push   %eax
 804870f:	68 00 01 00 00       	push   $0x100
 8048714:	8d 85 f4 fe ff ff    	lea    -0x10c(%ebp),%eax
 804871a:	50                   	push   %eax
 804871b:	e8 50 fd ff ff       	call   8048470 <fgets@plt>
 8048720:	83 c4 10             	add    $0x10,%esp
 8048723:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048728:	89 c2                	mov    %eax,%edx
 804872a:	83 ec 04             	sub    $0x4,%esp
 804872d:	6a 1e                	push   $0x1e
 804872f:	8d 85 f4 fe ff ff    	lea    -0x10c(%ebp),%eax
 8048735:	50                   	push   %eax
 8048736:	52                   	push   %edx
 8048737:	e8 94 fd ff ff       	call   80484d0 <strncpy@plt>
 804873c:	83 c4 10             	add    $0x10,%esp
 804873f:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048744:	83 ec 0c             	sub    $0xc,%esp
 8048747:	50                   	push   %eax
 8048748:	e8 63 fd ff ff       	call   80484b0 <strlen@plt>
 804874d:	83 c4 10             	add    $0x10,%esp
 8048750:	89 85 f0 fe ff ff    	mov    %eax,-0x110(%ebp)
 8048756:	83 bd f0 fe ff ff 1e 	cmpl   $0x1e,-0x110(%ebp)
 804875d:	7f 14                	jg     8048773 <main+0x117>
 804875f:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048764:	8b 95 f0 fe ff ff    	mov    -0x110(%ebp),%edx
 804876a:	83 ea 01             	sub    $0x1,%edx
 804876d:	c6 04 10 00          	movb   $0x0,(%eax,%edx,1)
 8048771:	eb 09                	jmp    804877c <main+0x120>
 8048773:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048778:	c6 40 1f 00          	movb   $0x0,0x1f(%eax)
 804877c:	83 ec 0c             	sub    $0xc,%esp
 804877f:	68 d0 8a 04 08       	push   $0x8048ad0
 8048784:	e8 a7 fc ff ff       	call   8048430 <printf@plt>
 8048789:	83 c4 10             	add    $0x10,%esp
 804878c:	a1 40 a0 04 08       	mov    0x804a040,%eax
 8048791:	83 ec 04             	sub    $0x4,%esp
 8048794:	50                   	push   %eax
 8048795:	68 00 01 00 00       	push   $0x100
 804879a:	8d 85 f4 fe ff ff    	lea    -0x10c(%ebp),%eax
 80487a0:	50                   	push   %eax
 80487a1:	e8 ca fc ff ff       	call   8048470 <fgets@plt>
 80487a6:	83 c4 10             	add    $0x10,%esp
 80487a9:	a1 48 a0 04 08       	mov    0x804a048,%eax
 80487ae:	8d 50 20             	lea    0x20(%eax),%edx
 80487b1:	83 ec 04             	sub    $0x4,%esp
 80487b4:	6a 1e                	push   $0x1e
 80487b6:	8d 85 f4 fe ff ff    	lea    -0x10c(%ebp),%eax
 80487bc:	50                   	push   %eax
 80487bd:	52                   	push   %edx
 80487be:	e8 0d fd ff ff       	call   80484d0 <strncpy@plt>
 80487c3:	83 c4 10             	add    $0x10,%esp
 80487c6:	a1 48 a0 04 08       	mov    0x804a048,%eax
 80487cb:	83 c0 20             	add    $0x20,%eax
 80487ce:	83 ec 0c             	sub    $0xc,%esp
 80487d1:	50                   	push   %eax
 80487d2:	e8 d9 fc ff ff       	call   80484b0 <strlen@plt>
 80487d7:	83 c4 10             	add    $0x10,%esp
 80487da:	89 85 f0 fe ff ff    	mov    %eax,-0x110(%ebp)
 80487e0:	83 bd f0 fe ff ff 1e 	cmpl   $0x1e,-0x110(%ebp)
 80487e7:	7f 15                	jg     80487fe <main+0x1a2>
 80487e9:	a1 48 a0 04 08       	mov    0x804a048,%eax
 80487ee:	8b 95 f0 fe ff ff    	mov    -0x110(%ebp),%edx
 80487f4:	83 ea 01             	sub    $0x1,%edx
 80487f7:	c6 44 10 20 00       	movb   $0x0,0x20(%eax,%edx,1)
 80487fc:	eb 09                	jmp    8048807 <main+0x1ab>
 80487fe:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048803:	c6 40 3f 00          	movb   $0x0,0x3f(%eax)
 8048807:	a1 48 a0 04 08       	mov    0x804a048,%eax
 804880c:	83 ec 08             	sub    $0x8,%esp
 804880f:	50                   	push   %eax
 8048810:	68 dc 8a 04 08       	push   $0x8048adc
 8048815:	e8 16 fc ff ff       	call   8048430 <printf@plt>
 804881a:	83 c4 10             	add    $0x10,%esp
 804881d:	e9 2e 01 00 00       	jmp    8048950 <main+0x2f4>
 8048822:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048827:	85 c0                	test   %eax,%eax
 8048829:	75 15                	jne    8048840 <main+0x1e4>
 804882b:	83 ec 0c             	sub    $0xc,%esp
 804882e:	68 01 8b 04 08       	push   $0x8048b01
 8048833:	e8 58 fc ff ff       	call   8048490 <puts@plt>
 8048838:	83 c4 10             	add    $0x10,%esp
 804883b:	e9 10 01 00 00       	jmp    8048950 <main+0x2f4>
 8048840:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048845:	8b 50 40             	mov    0x40(%eax),%edx
 8048848:	a1 48 a0 04 08       	mov    0x804a048,%eax
 804884d:	8d 48 20             	lea    0x20(%eax),%ecx
 8048850:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048855:	89 c3                	mov    %eax,%ebx
 8048857:	a1 48 a0 04 08       	mov    0x804a048,%eax
 804885c:	83 ec 0c             	sub    $0xc,%esp
 804885f:	52                   	push   %edx
 8048860:	51                   	push   %ecx
 8048861:	53                   	push   %ebx
 8048862:	50                   	push   %eax
 8048863:	68 1c 8b 04 08       	push   $0x8048b1c
 8048868:	e8 c3 fb ff ff       	call   8048430 <printf@plt>
 804886d:	83 c4 20             	add    $0x20,%esp
 8048870:	e9 db 00 00 00       	jmp    8048950 <main+0x2f4>
 8048875:	a1 48 a0 04 08       	mov    0x804a048,%eax
 804887a:	85 c0                	test   %eax,%eax
 804887c:	75 15                	jne    8048893 <main+0x237>
 804887e:	83 ec 0c             	sub    $0xc,%esp
 8048881:	68 01 8b 04 08       	push   $0x8048b01
 8048886:	e8 05 fc ff ff       	call   8048490 <puts@plt>
 804888b:	83 c4 10             	add    $0x10,%esp
 804888e:	e9 bd 00 00 00       	jmp    8048950 <main+0x2f4>
 8048893:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048898:	83 ec 0c             	sub    $0xc,%esp
 804889b:	50                   	push   %eax
 804889c:	e8 9f fb ff ff       	call   8048440 <free@plt>
 80488a1:	83 c4 10             	add    $0x10,%esp
 80488a4:	83 ec 0c             	sub    $0xc,%esp
 80488a7:	68 81 8b 04 08       	push   $0x8048b81
 80488ac:	e8 df fb ff ff       	call   8048490 <puts@plt>
 80488b1:	83 c4 10             	add    $0x10,%esp
 80488b4:	e9 97 00 00 00       	jmp    8048950 <main+0x2f4>
 80488b9:	83 ec 0c             	sub    $0xc,%esp
 80488bc:	68 9f 8b 04 08       	push   $0x8048b9f
 80488c1:	e8 ca fb ff ff       	call   8048490 <puts@plt>
 80488c6:	83 c4 10             	add    $0x10,%esp
 80488c9:	a1 40 a0 04 08       	mov    0x804a040,%eax
 80488ce:	83 ec 04             	sub    $0x4,%esp
 80488d1:	50                   	push   %eax
 80488d2:	68 00 01 00 00       	push   $0x100
 80488d7:	8d 85 f4 fe ff ff    	lea    -0x10c(%ebp),%eax
 80488dd:	50                   	push   %eax
 80488de:	e8 8d fb ff ff       	call   8048470 <fgets@plt>
 80488e3:	83 c4 10             	add    $0x10,%esp
 80488e6:	83 ec 0c             	sub    $0xc,%esp
 80488e9:	8d 85 f4 fe ff ff    	lea    -0x10c(%ebp),%eax
 80488ef:	50                   	push   %eax
 80488f0:	e8 5b fb ff ff       	call   8048450 <strdup@plt>
 80488f5:	83 c4 10             	add    $0x10,%esp
 80488f8:	a3 4c a0 04 08       	mov    %eax,0x804a04c
 80488fd:	a1 4c a0 04 08       	mov    0x804a04c,%eax
 8048902:	83 ec 08             	sub    $0x8,%esp
 8048905:	50                   	push   %eax
 8048906:	68 b4 8b 04 08       	push   $0x8048bb4
 804890b:	e8 20 fb ff ff       	call   8048430 <printf@plt>
 8048910:	83 c4 10             	add    $0x10,%esp
 8048913:	eb 3b                	jmp    8048950 <main+0x2f4>
 8048915:	a1 48 a0 04 08       	mov    0x804a048,%eax
 804891a:	85 c0                	test   %eax,%eax
 804891c:	74 21                	je     804893f <main+0x2e3>
 804891e:	a1 48 a0 04 08       	mov    0x804a048,%eax
 8048923:	8b 40 40             	mov    0x40(%eax),%eax
 8048926:	3d 66 75 63 6b       	cmp    $0x6b637566,%eax
 804892b:	75 12                	jne    804893f <main+0x2e3>
 804892d:	83 ec 0c             	sub    $0xc,%esp
 8048930:	68 f4 8b 04 08       	push   $0x8048bf4
 8048935:	e8 66 fb ff ff       	call   80484a0 <system@plt>
 804893a:	83 c4 10             	add    $0x10,%esp
 804893d:	eb 10                	jmp    804894f <main+0x2f3>
 804893f:	83 ec 0c             	sub    $0xc,%esp
 8048942:	68 02 8c 04 08       	push   $0x8048c02
 8048947:	e8 44 fb ff ff       	call   8048490 <puts@plt>
 804894c:	83 c4 10             	add    $0x10,%esp
 804894f:	90                   	nop
 8048950:	e9 3e fd ff ff       	jmp    8048693 <main+0x37>
 8048955:	66 90                	xchg   %ax,%ax
 8048957:	66 90                	xchg   %ax,%ax
 8048959:	66 90                	xchg   %ax,%ax
 804895b:	66 90                	xchg   %ax,%ax
 804895d:	66 90                	xchg   %ax,%ax
 804895f:	90                   	nop

08048960 <__libc_csu_init>:
 8048960:	55                   	push   %ebp
 8048961:	57                   	push   %edi
 8048962:	56                   	push   %esi
 8048963:	53                   	push   %ebx
 8048964:	e8 b7 fb ff ff       	call   8048520 <__x86.get_pc_thunk.bx>
 8048969:	81 c3 97 16 00 00    	add    $0x1697,%ebx
 804896f:	83 ec 0c             	sub    $0xc,%esp
 8048972:	8b 6c 24 20          	mov    0x20(%esp),%ebp
 8048976:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 804897c:	e8 73 fa ff ff       	call   80483f4 <_init>
 8048981:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 8048987:	29 c6                	sub    %eax,%esi
 8048989:	c1 fe 02             	sar    $0x2,%esi
 804898c:	85 f6                	test   %esi,%esi
 804898e:	74 25                	je     80489b5 <__libc_csu_init+0x55>
 8048990:	31 ff                	xor    %edi,%edi
 8048992:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048998:	83 ec 04             	sub    $0x4,%esp
 804899b:	ff 74 24 2c          	pushl  0x2c(%esp)
 804899f:	ff 74 24 2c          	pushl  0x2c(%esp)
 80489a3:	55                   	push   %ebp
 80489a4:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 80489ab:	83 c7 01             	add    $0x1,%edi
 80489ae:	83 c4 10             	add    $0x10,%esp
 80489b1:	39 f7                	cmp    %esi,%edi
 80489b3:	75 e3                	jne    8048998 <__libc_csu_init+0x38>
 80489b5:	83 c4 0c             	add    $0xc,%esp
 80489b8:	5b                   	pop    %ebx
 80489b9:	5e                   	pop    %esi
 80489ba:	5f                   	pop    %edi
 80489bb:	5d                   	pop    %ebp
 80489bc:	c3                   	ret    
 80489bd:	8d 76 00             	lea    0x0(%esi),%esi

080489c0 <__libc_csu_fini>:
 80489c0:	f3 c3                	repz ret 

Disassembly of section .fini:

080489c4 <_fini>:
 80489c4:	53                   	push   %ebx
 80489c5:	83 ec 08             	sub    $0x8,%esp
 80489c8:	e8 53 fb ff ff       	call   8048520 <__x86.get_pc_thunk.bx>
 80489cd:	81 c3 33 16 00 00    	add    $0x1633,%ebx
 80489d3:	83 c4 08             	add    $0x8,%esp
 80489d6:	5b                   	pop    %ebx
 80489d7:	c3                   	ret    

Disassembly of section .rodata:

080489d8 <_fp_hw>:
 80489d8:	03 00                	add    (%eax),%eax
	...

080489dc <_IO_stdin_used>:
 80489dc:	01 00                	add    %eax,(%eax)
 80489de:	02 00                	add    (%eax),%al
 80489e0:	0a 23                	or     (%ebx),%ah
 80489e2:	23 23                	and    (%ebx),%esp
 80489e4:	23 23                	and    (%ebx),%esp
 80489e6:	23 23                	and    (%ebx),%esp
 80489e8:	23 23                	and    (%ebx),%esp
 80489ea:	23 23                	and    (%ebx),%esp
 80489ec:	23 23                	and    (%ebx),%esp
 80489ee:	23 23                	and    (%ebx),%esp
 80489f0:	23 23                	and    (%ebx),%esp
 80489f2:	23 23                	and    (%ebx),%esp
 80489f4:	23 20                	and    (%eax),%esp
 80489f6:	57                   	push   %edi
 80489f7:	65 6c                	gs insb (%dx),%es:(%edi)
 80489f9:	63 6f 6d             	arpl   %bp,0x6d(%edi)
 80489fc:	65 20 74 6f 20       	and    %dh,%gs:0x20(%edi,%ebp,2)
 8048a01:	4c                   	dec    %esp
 8048a02:	69 74 74 6c 65 20 54 	imul   $0x6f542065,0x6c(%esp,%esi,2),%esi
 8048a09:	6f 
 8048a0a:	6d                   	insl   (%dx),%es:(%edi)
 8048a0b:	6d                   	insl   (%dx),%es:(%edi)
 8048a0c:	79 27                	jns    8048a35 <_IO_stdin_used+0x59>
 8048a0e:	73 20                	jae    8048a30 <_IO_stdin_used+0x54>
 8048a10:	48                   	dec    %eax
 8048a11:	61                   	popa   
 8048a12:	6e                   	outsb  %ds:(%esi),(%dx)
 8048a13:	64 79 20             	fs jns 8048a36 <_IO_stdin_used+0x5a>
 8048a16:	79 65                	jns    8048a7d <_IO_stdin_used+0xa1>
 8048a18:	74 20                	je     8048a3a <_IO_stdin_used+0x5e>
 8048a1a:	45                   	inc    %ebp
 8048a1b:	6c                   	insb   (%dx),%es:(%edi)
 8048a1c:	65 67 61             	gs addr16 popa 
 8048a1f:	6e                   	outsb  %ds:(%esi),(%dx)
 8048a20:	74 20                	je     8048a42 <_IO_stdin_used+0x66>
 8048a22:	61                   	popa   
 8048a23:	6e                   	outsb  %ds:(%esi),(%dx)
 8048a24:	64 20 41 64          	and    %al,%fs:0x64(%ecx)
 8048a28:	76 61                	jbe    8048a8b <_IO_stdin_used+0xaf>
 8048a2a:	6e                   	outsb  %ds:(%esi),(%dx)
 8048a2b:	63 65 64             	arpl   %sp,0x64(%ebp)
 8048a2e:	20 50 72             	and    %dl,0x72(%eax)
 8048a31:	6f                   	outsl  %ds:(%esi),(%dx)
 8048a32:	67 72 61             	addr16 jb 8048a96 <_IO_stdin_used+0xba>
 8048a35:	6d                   	insl   (%dx),%es:(%edi)
 8048a36:	20 23                	and    %ah,(%ebx)
 8048a38:	23 23                	and    (%ebx),%esp
 8048a3a:	23 23                	and    (%ebx),%esp
 8048a3c:	23 23                	and    (%ebx),%esp
 8048a3e:	23 23                	and    (%ebx),%esp
 8048a40:	23 23                	and    (%ebx),%esp
 8048a42:	23 23                	and    (%ebx),%esp
 8048a44:	23 23                	and    (%ebx),%esp
 8048a46:	23 23                	and    (%ebx),%esp
 8048a48:	23 23                	and    (%ebx),%esp
 8048a4a:	23 00                	and    (%eax),%eax
 8048a4c:	0a 31                	or     (%ecx),%dh
 8048a4e:	2e 20 43 72          	and    %al,%cs:0x72(%ebx)
 8048a52:	65 61                	gs popa 
 8048a54:	74 65                	je     8048abb <_IO_stdin_used+0xdf>
 8048a56:	20 61 63             	and    %ah,0x63(%ecx)
 8048a59:	63 6f 75             	arpl   %bp,0x75(%edi)
 8048a5c:	6e                   	outsb  %ds:(%esi),(%dx)
 8048a5d:	74 0a                	je     8048a69 <_IO_stdin_used+0x8d>
 8048a5f:	32 2e                	xor    (%esi),%ch
 8048a61:	20 44 69 73          	and    %al,0x73(%ecx,%ebp,2)
 8048a65:	70 6c                	jo     8048ad3 <_IO_stdin_used+0xf7>
 8048a67:	61                   	popa   
 8048a68:	79 20                	jns    8048a8a <_IO_stdin_used+0xae>
 8048a6a:	61                   	popa   
 8048a6b:	63 63 6f             	arpl   %sp,0x6f(%ebx)
 8048a6e:	75 6e                	jne    8048ade <_IO_stdin_used+0x102>
 8048a70:	74 0a                	je     8048a7c <_IO_stdin_used+0xa0>
 8048a72:	33 2e                	xor    (%esi),%ebp
 8048a74:	20 44 65 6c          	and    %al,0x6c(%ebp,%eiz,2)
 8048a78:	65 74 65             	gs je  8048ae0 <_IO_stdin_used+0x104>
 8048a7b:	20 61 63             	and    %ah,0x63(%ecx)
 8048a7e:	63 6f 75             	arpl   %bp,0x75(%edi)
 8048a81:	6e                   	outsb  %ds:(%esi),(%dx)
 8048a82:	74 0a                	je     8048a8e <_IO_stdin_used+0xb2>
 8048a84:	34 2e                	xor    $0x2e,%al
 8048a86:	20 41 64             	and    %al,0x64(%ecx)
 8048a89:	64 20 6d 65          	and    %ch,%fs:0x65(%ebp)
 8048a8d:	6d                   	insl   (%dx),%es:(%edi)
 8048a8e:	6f                   	outsl  %ds:(%esi),(%dx)
 8048a8f:	0a 35 2e 20 50 72    	or     0x7250202e,%dh
 8048a95:	69 6e 74 20 66 6c 61 	imul   $0x616c6620,0x74(%esi),%ebp
 8048a9c:	67 0a 0a             	or     (%bp,%si),%cl
 8048a9f:	50                   	push   %eax
 8048aa0:	6c                   	insb   (%dx),%es:(%edi)
 8048aa1:	65 61                	gs popa 
 8048aa3:	73 65                	jae    8048b0a <_IO_stdin_used+0x12e>
 8048aa5:	20 65 6e             	and    %ah,0x6e(%ebp)
 8048aa8:	74 65                	je     8048b0f <_IO_stdin_used+0x133>
 8048aaa:	72 20                	jb     8048acc <_IO_stdin_used+0xf0>
 8048aac:	61                   	popa   
 8048aad:	6e                   	outsb  %ds:(%esi),(%dx)
 8048aae:	20 6f 70             	and    %ch,0x70(%edi)
 8048ab1:	65 72 61             	gs jb  8048b15 <_IO_stdin_used+0x139>
 8048ab4:	74 69                	je     8048b1f <_IO_stdin_used+0x143>
 8048ab6:	6f                   	outsl  %ds:(%esi),(%dx)
 8048ab7:	6e                   	outsb  %ds:(%esi),(%dx)
 8048ab8:	20 6e 75             	and    %ch,0x75(%esi)
 8048abb:	6d                   	insl   (%dx),%es:(%edi)
 8048abc:	62 65 72             	bound  %esp,0x72(%ebp)
 8048abf:	3a 20                	cmp    (%eax),%ah
 8048ac1:	00 0a                	add    %cl,(%edx)
 8048ac3:	46                   	inc    %esi
 8048ac4:	69 72 73 74 20 6e 61 	imul   $0x616e2074,0x73(%edx),%esi
 8048acb:	6d                   	insl   (%dx),%es:(%edi)
 8048acc:	65 3a 20             	cmp    %gs:(%eax),%ah
 8048acf:	00 4c 61 73          	add    %cl,0x73(%ecx,%eiz,2)
 8048ad3:	74 20                	je     8048af5 <_IO_stdin_used+0x119>
 8048ad5:	6e                   	outsb  %ds:(%esi),(%dx)
 8048ad6:	61                   	popa   
 8048ad7:	6d                   	insl   (%dx),%es:(%edi)
 8048ad8:	65 3a 20             	cmp    %gs:(%eax),%ah
 8048adb:	00 0a                	add    %cl,(%edx)
 8048add:	54                   	push   %esp
 8048ade:	68 61 6e 6b 20       	push   $0x206b6e61
 8048ae3:	79 6f                	jns    8048b54 <_IO_stdin_used+0x178>
 8048ae5:	75 2c                	jne    8048b13 <_IO_stdin_used+0x137>
 8048ae7:	20 79 6f             	and    %bh,0x6f(%ecx)
 8048aea:	75 72                	jne    8048b5e <_IO_stdin_used+0x182>
 8048aec:	20 61 63             	and    %ah,0x63(%ecx)
 8048aef:	63 6f 75             	arpl   %bp,0x75(%edi)
 8048af2:	6e                   	outsb  %ds:(%esi),(%dx)
 8048af3:	74 20                	je     8048b15 <_IO_stdin_used+0x139>
 8048af5:	6e                   	outsb  %ds:(%esi),(%dx)
 8048af6:	75 6d                	jne    8048b65 <_IO_stdin_used+0x189>
 8048af8:	62 65 72             	bound  %esp,0x72(%ebp)
 8048afb:	20 25 64 2e 0a 00    	and    %ah,0xa2e64
 8048b01:	0a 53 6f             	or     0x6f(%ebx),%dl
 8048b04:	72 72                	jb     8048b78 <_IO_stdin_used+0x19c>
 8048b06:	79 2c                	jns    8048b34 <_IO_stdin_used+0x158>
 8048b08:	20 6e 6f             	and    %ch,0x6f(%esi)
 8048b0b:	20 61 63             	and    %ah,0x63(%ecx)
 8048b0e:	63 6f 75             	arpl   %bp,0x75(%edi)
 8048b11:	6e                   	outsb  %ds:(%esi),(%dx)
 8048b12:	74 20                	je     8048b34 <_IO_stdin_used+0x158>
 8048b14:	66 6f                	outsw  %ds:(%esi),(%dx)
 8048b16:	75 6e                	jne    8048b86 <_IO_stdin_used+0x1aa>
 8048b18:	64 2e 00 00          	fs add %al,%cs:(%eax)
 8048b1c:	0a 23                	or     (%ebx),%ah
 8048b1e:	23 23                	and    (%ebx),%esp
 8048b20:	23 23                	and    (%ebx),%esp
 8048b22:	23 23                	and    (%ebx),%esp
 8048b24:	23 23                	and    (%ebx),%esp
 8048b26:	23 23                	and    (%ebx),%esp
 8048b28:	23 23                	and    (%ebx),%esp
 8048b2a:	23 23                	and    (%ebx),%esp
 8048b2c:	23 20                	and    (%eax),%esp
 8048b2e:	41                   	inc    %ecx
 8048b2f:	63 63 6f             	arpl   %sp,0x6f(%ebx)
 8048b32:	75 6e                	jne    8048ba2 <_IO_stdin_used+0x1c6>
 8048b34:	74 20                	je     8048b56 <_IO_stdin_used+0x17a>
 8048b36:	6e                   	outsb  %ds:(%esi),(%dx)
 8048b37:	6f                   	outsl  %ds:(%esi),(%dx)
 8048b38:	2e 20 25 64 20 23 23 	and    %ah,%cs:0x23232064
 8048b3f:	23 23                	and    (%ebx),%esp
 8048b41:	23 23                	and    (%ebx),%esp
 8048b43:	23 23                	and    (%ebx),%esp
 8048b45:	23 23                	and    (%ebx),%esp
 8048b47:	23 23                	and    (%ebx),%esp
 8048b49:	23 23                	and    (%ebx),%esp
 8048b4b:	23 23                	and    (%ebx),%esp
 8048b4d:	0a 46 69             	or     0x69(%esi),%al
 8048b50:	72 73                	jb     8048bc5 <_IO_stdin_used+0x1e9>
 8048b52:	74 20                	je     8048b74 <_IO_stdin_used+0x198>
 8048b54:	6e                   	outsb  %ds:(%esi),(%dx)
 8048b55:	61                   	popa   
 8048b56:	6d                   	insl   (%dx),%es:(%edi)
 8048b57:	65 3a 20             	cmp    %gs:(%eax),%ah
 8048b5a:	25 73 0a 4c 61       	and    $0x614c0a73,%eax
 8048b5f:	73 74                	jae    8048bd5 <_IO_stdin_used+0x1f9>
 8048b61:	20 6e 61             	and    %ch,0x61(%esi)
 8048b64:	6d                   	insl   (%dx),%es:(%edi)
 8048b65:	65 3a 20             	cmp    %gs:(%eax),%ah
 8048b68:	25 73 0a 41 63       	and    $0x63410a73,%eax
 8048b6d:	63 6f 75             	arpl   %bp,0x75(%edi)
 8048b70:	6e                   	outsb  %ds:(%esi),(%dx)
 8048b71:	74 20                	je     8048b93 <_IO_stdin_used+0x1b7>
 8048b73:	62 61 6c             	bound  %esp,0x6c(%ecx)
 8048b76:	61                   	popa   
 8048b77:	6e                   	outsb  %ds:(%esi),(%dx)
 8048b78:	63 65 3a             	arpl   %sp,0x3a(%ebp)
 8048b7b:	20 25 64 0a 0a 00    	and    %ah,0xa0a64
 8048b81:	0a 41 63             	or     0x63(%ecx),%al
 8048b84:	63 6f 75             	arpl   %bp,0x75(%edi)
 8048b87:	6e                   	outsb  %ds:(%esi),(%dx)
 8048b88:	74 20                	je     8048baa <_IO_stdin_used+0x1ce>
 8048b8a:	64 65 6c             	fs gs insb (%dx),%es:(%edi)
 8048b8d:	65 74 65             	gs je  8048bf5 <_IO_stdin_used+0x219>
 8048b90:	64 20 73 75          	and    %dh,%fs:0x75(%ebx)
 8048b94:	63 63 65             	arpl   %sp,0x65(%ebx)
 8048b97:	73 73                	jae    8048c0c <_IO_stdin_used+0x230>
 8048b99:	66 75 6c             	data16 jne 8048c08 <_IO_stdin_used+0x22c>
 8048b9c:	6c                   	insb   (%dx),%es:(%edi)
 8048b9d:	79 00                	jns    8048b9f <_IO_stdin_used+0x1c3>
 8048b9f:	0a 50 6c             	or     0x6c(%eax),%dl
 8048ba2:	65 61                	gs popa 
 8048ba4:	73 65                	jae    8048c0b <_IO_stdin_used+0x22f>
 8048ba6:	20 65 6e             	and    %ah,0x6e(%ebp)
 8048ba9:	74 65                	je     8048c10 <_IO_stdin_used+0x234>
 8048bab:	72 20                	jb     8048bcd <_IO_stdin_used+0x1f1>
 8048bad:	6d                   	insl   (%dx),%es:(%edi)
 8048bae:	65 6d                	gs insl (%dx),%es:(%edi)
 8048bb0:	6f                   	outsl  %ds:(%esi),(%dx)
 8048bb1:	3a 00                	cmp    (%eax),%al
 8048bb3:	00 0a                	add    %cl,(%edx)
 8048bb5:	54                   	push   %esp
 8048bb6:	68 61 6e 6b 20       	push   $0x206b6e61
 8048bbb:	79 6f                	jns    8048c2c <__GNU_EH_FRAME_HDR+0xc>
 8048bbd:	75 2c                	jne    8048beb <_IO_stdin_used+0x20f>
 8048bbf:	20 70 6c             	and    %dh,0x6c(%eax)
 8048bc2:	65 61                	gs popa 
 8048bc4:	73 65                	jae    8048c2b <__GNU_EH_FRAME_HDR+0xb>
 8048bc6:	20 6b 65             	and    %ch,0x65(%ebx)
 8048bc9:	65 70 20             	gs jo  8048bec <_IO_stdin_used+0x210>
 8048bcc:	74 68                	je     8048c36 <__GNU_EH_FRAME_HDR+0x16>
 8048bce:	69 73 20 72 65 66 65 	imul   $0x65666572,0x20(%ebx),%esi
 8048bd5:	72 65                	jb     8048c3c <__GNU_EH_FRAME_HDR+0x1c>
 8048bd7:	6e                   	outsb  %ds:(%esi),(%dx)
 8048bd8:	63 65 20             	arpl   %sp,0x20(%ebp)
 8048bdb:	6e                   	outsb  %ds:(%esi),(%dx)
 8048bdc:	75 6d                	jne    8048c4b <__GNU_EH_FRAME_HDR+0x2b>
 8048bde:	62 65 72             	bound  %esp,0x72(%ebp)
 8048be1:	20 6e 75             	and    %ch,0x75(%esi)
 8048be4:	6d                   	insl   (%dx),%es:(%edi)
 8048be5:	62 65 72             	bound  %esp,0x72(%ebp)
 8048be8:	20 73 61             	and    %dh,0x61(%ebx)
 8048beb:	66 65 3a 20          	data16 cmp %gs:(%eax),%ah
 8048bef:	25 64 2e 0a 00       	and    $0xa2e64,%eax
 8048bf4:	2f                   	das    
 8048bf5:	62 69 6e             	bound  %ebp,0x6e(%ecx)
 8048bf8:	2f                   	das    
 8048bf9:	63 61 74             	arpl   %sp,0x74(%ecx)
 8048bfc:	20 66 6c             	and    %ah,0x6c(%esi)
 8048bff:	61                   	popa   
 8048c00:	67 00 0a             	add    %cl,(%bp,%si)
 8048c03:	4e                   	dec    %esi
 8048c04:	6f                   	outsl  %ds:(%esi),(%dx)
 8048c05:	70 65                	jo     8048c6c <__GNU_EH_FRAME_HDR+0x4c>
 8048c07:	2e 00 00             	add    %al,%cs:(%eax)
 8048c0a:	00 00                	add    %al,(%eax)
 8048c0c:	e4 86                	in     $0x86,%al
 8048c0e:	04 08                	add    $0x8,%al
 8048c10:	22 88 04 08 75 88    	and    -0x778af7fc(%eax),%cl
 8048c16:	04 08                	add    $0x8,%al
 8048c18:	b9 88 04 08 15       	mov    $0x15080488,%ecx
 8048c1d:	89 04 08             	mov    %eax,(%eax,%ecx,1)

Disassembly of section .eh_frame_hdr:

08048c20 <__GNU_EH_FRAME_HDR>:
 8048c20:	01 1b                	add    %ebx,(%ebx)
 8048c22:	03 3b                	add    (%ebx),%edi
 8048c24:	30 00                	xor    %al,(%eax)
 8048c26:	00 00                	add    %al,(%eax)
 8048c28:	05 00 00 00 00       	add    $0x0,%eax
 8048c2d:	f8                   	clc    
 8048c2e:	ff                   	(bad)  
 8048c2f:	ff 4c 00 00          	decl   0x0(%eax,%eax,1)
 8048c33:	00 cb                	add    %cl,%bl
 8048c35:	f9                   	stc    
 8048c36:	ff                   	(bad)  
 8048c37:	ff 70 00             	pushl  0x0(%eax)
 8048c3a:	00 00                	add    %al,(%eax)
 8048c3c:	3c fa                	cmp    $0xfa,%al
 8048c3e:	ff                   	(bad)  
 8048c3f:	ff 90 00 00 00 40    	call   *0x40000000(%eax)
 8048c45:	fd                   	std    
 8048c46:	ff                   	(bad)  
 8048c47:	ff                   	(bad)  
 8048c48:	b8 00 00 00 a0       	mov    $0xa0000000,%eax
 8048c4d:	fd                   	std    
 8048c4e:	ff                   	(bad)  
 8048c4f:	ff 04 01             	incl   (%ecx,%eax,1)
	...

Disassembly of section .eh_frame:

08048c54 <__FRAME_END__-0xe4>:
 8048c54:	14 00                	adc    $0x0,%al
 8048c56:	00 00                	add    %al,(%eax)
 8048c58:	00 00                	add    %al,(%eax)
 8048c5a:	00 00                	add    %al,(%eax)
 8048c5c:	01 7a 52             	add    %edi,0x52(%edx)
 8048c5f:	00 01                	add    %al,(%ecx)
 8048c61:	7c 08                	jl     8048c6b <__GNU_EH_FRAME_HDR+0x4b>
 8048c63:	01 1b                	add    %ebx,(%ebx)
 8048c65:	0c 04                	or     $0x4,%al
 8048c67:	04 88                	add    $0x88,%al
 8048c69:	01 00                	add    %eax,(%eax)
 8048c6b:	00 20                	add    %ah,(%eax)
 8048c6d:	00 00                	add    %al,(%eax)
 8048c6f:	00 1c 00             	add    %bl,(%eax,%eax,1)
 8048c72:	00 00                	add    %al,(%eax)
 8048c74:	ac                   	lods   %ds:(%esi),%al
 8048c75:	f7 ff                	idiv   %edi
 8048c77:	ff c0                	inc    %eax
 8048c79:	00 00                	add    %al,(%eax)
 8048c7b:	00 00                	add    %al,(%eax)
 8048c7d:	0e                   	push   %cs
 8048c7e:	08 46 0e             	or     %al,0xe(%esi)
 8048c81:	0c 4a                	or     $0x4a,%al
 8048c83:	0f 0b                	ud2    
 8048c85:	74 04                	je     8048c8b <__GNU_EH_FRAME_HDR+0x6b>
 8048c87:	78 00                	js     8048c89 <__GNU_EH_FRAME_HDR+0x69>
 8048c89:	3f                   	aas    
 8048c8a:	1a 3b                	sbb    (%ebx),%bh
 8048c8c:	2a 32                	sub    (%edx),%dh
 8048c8e:	24 22                	and    $0x22,%al
 8048c90:	1c 00                	sbb    $0x0,%al
 8048c92:	00 00                	add    %al,(%eax)
 8048c94:	40                   	inc    %eax
 8048c95:	00 00                	add    %al,(%eax)
 8048c97:	00 53 f9             	add    %dl,-0x7(%ebx)
 8048c9a:	ff                   	(bad)  
 8048c9b:	ff 71 00             	pushl  0x0(%ecx)
 8048c9e:	00 00                	add    %al,(%eax)
 8048ca0:	00 41 0e             	add    %al,0xe(%ecx)
 8048ca3:	08 85 02 42 0d 05    	or     %al,0x50d4202(%ebp)
 8048ca9:	02 6d c5             	add    -0x3b(%ebp),%ch
 8048cac:	0c 04                	or     $0x4,%al
 8048cae:	04 00                	add    $0x0,%al
 8048cb0:	24 00                	and    $0x0,%al
 8048cb2:	00 00                	add    %al,(%eax)
 8048cb4:	60                   	pusha  
 8048cb5:	00 00                	add    %al,(%eax)
 8048cb7:	00 a4 f9 ff ff f9 02 	add    %ah,0x2f9ffff(%ecx,%edi,8)
 8048cbe:	00 00                	add    %al,(%eax)
 8048cc0:	00 44 0c 01          	add    %al,0x1(%esp,%ecx,1)
 8048cc4:	00 47 10             	add    %al,0x10(%edi)
 8048cc7:	05 02 75 00 44       	add    $0x44007502,%eax
 8048ccc:	0f 03 75 78          	lsl    0x78(%ebp),%esi
 8048cd0:	06                   	push   %es
 8048cd1:	10 03                	adc    %al,(%ebx)
 8048cd3:	02 75 7c             	add    0x7c(%ebp),%dh
 8048cd6:	00 00                	add    %al,(%eax)
 8048cd8:	48                   	dec    %eax
 8048cd9:	00 00                	add    %al,(%eax)
 8048cdb:	00 88 00 00 00 80    	add    %cl,-0x80000000(%eax)
 8048ce1:	fc                   	cld    
 8048ce2:	ff                   	(bad)  
 8048ce3:	ff 5d 00             	lcall  *0x0(%ebp)
 8048ce6:	00 00                	add    %al,(%eax)
 8048ce8:	00 41 0e             	add    %al,0xe(%ecx)
 8048ceb:	08 85 02 41 0e 0c    	or     %al,0xc0e4102(%ebp)
 8048cf1:	87 03                	xchg   %eax,(%ebx)
 8048cf3:	41                   	inc    %ecx
 8048cf4:	0e                   	push   %cs
 8048cf5:	10 86 04 41 0e 14    	adc    %al,0x140e4104(%esi)
 8048cfb:	83 05 4e 0e 20 69 0e 	addl   $0xe,0x69200e4e
 8048d02:	24 44                	and    $0x44,%al
 8048d04:	0e                   	push   %cs
 8048d05:	28 44 0e 2c          	sub    %al,0x2c(%esi,%ecx,1)
 8048d09:	41                   	inc    %ecx
 8048d0a:	0e                   	push   %cs
 8048d0b:	30 4d 0e             	xor    %cl,0xe(%ebp)
 8048d0e:	20 47 0e             	and    %al,0xe(%edi)
 8048d11:	14 41                	adc    $0x41,%al
 8048d13:	c3                   	ret    
 8048d14:	0e                   	push   %cs
 8048d15:	10 41 c6             	adc    %al,-0x3a(%ecx)
 8048d18:	0e                   	push   %cs
 8048d19:	0c 41                	or     $0x41,%al
 8048d1b:	c7                   	(bad)  
 8048d1c:	0e                   	push   %cs
 8048d1d:	08 41 c5             	or     %al,-0x3b(%ecx)
 8048d20:	0e                   	push   %cs
 8048d21:	04 00                	add    $0x0,%al
 8048d23:	00 10                	add    %dl,(%eax)
 8048d25:	00 00                	add    %al,(%eax)
 8048d27:	00 d4                	add    %dl,%ah
 8048d29:	00 00                	add    %al,(%eax)
 8048d2b:	00 94 fc ff ff 02 00 	add    %dl,0x2ffff(%esp,%edi,8)
 8048d32:	00 00                	add    %al,(%eax)
 8048d34:	00 00                	add    %al,(%eax)
	...

08048d38 <__FRAME_END__>:
 8048d38:	00 00                	add    %al,(%eax)
	...

Disassembly of section .init_array:

08049f08 <__frame_dummy_init_array_entry>:
 8049f08:	c0                   	.byte 0xc0
 8049f09:	85 04 08             	test   %eax,(%eax,%ecx,1)

Disassembly of section .fini_array:

08049f0c <__do_global_dtors_aux_fini_array_entry>:
 8049f0c:	a0                   	.byte 0xa0
 8049f0d:	85 04 08             	test   %eax,(%eax,%ecx,1)

Disassembly of section .jcr:

08049f10 <__JCR_END__>:
 8049f10:	00 00                	add    %al,(%eax)
	...

Disassembly of section .dynamic:

08049f14 <_DYNAMIC>:
 8049f14:	01 00                	add    %eax,(%eax)
 8049f16:	00 00                	add    %al,(%eax)
 8049f18:	01 00                	add    %eax,(%eax)
 8049f1a:	00 00                	add    %al,(%eax)
 8049f1c:	0c 00                	or     $0x0,%al
 8049f1e:	00 00                	add    %al,(%eax)
 8049f20:	f4                   	hlt    
 8049f21:	83 04 08 0d          	addl   $0xd,(%eax,%ecx,1)
 8049f25:	00 00                	add    %al,(%eax)
 8049f27:	00 c4                	add    %al,%ah
 8049f29:	89 04 08             	mov    %eax,(%eax,%ecx,1)
 8049f2c:	19 00                	sbb    %eax,(%eax)
 8049f2e:	00 00                	add    %al,(%eax)
 8049f30:	08 9f 04 08 1b 00    	or     %bl,0x1b0804(%edi)
 8049f36:	00 00                	add    %al,(%eax)
 8049f38:	04 00                	add    $0x0,%al
 8049f3a:	00 00                	add    %al,(%eax)
 8049f3c:	1a 00                	sbb    (%eax),%al
 8049f3e:	00 00                	add    %al,(%eax)
 8049f40:	0c 9f                	or     $0x9f,%al
 8049f42:	04 08                	add    $0x8,%al
 8049f44:	1c 00                	sbb    $0x0,%al
 8049f46:	00 00                	add    %al,(%eax)
 8049f48:	04 00                	add    $0x0,%al
 8049f4a:	00 00                	add    %al,(%eax)
 8049f4c:	f5                   	cmc    
 8049f4d:	fe                   	(bad)  
 8049f4e:	ff 6f ac             	ljmp   *-0x54(%edi)
 8049f51:	81 04 08 05 00 00 00 	addl   $0x5,(%eax,%ecx,1)
 8049f58:	c0 82 04 08 06 00 00 	rolb   $0x0,0x60804(%edx)
 8049f5f:	00 d0                	add    %dl,%al
 8049f61:	81 04 08 0a 00 00 00 	addl   $0xa,(%eax,%ecx,1)
 8049f68:	8e 00                	mov    (%eax),%es
 8049f6a:	00 00                	add    %al,(%eax)
 8049f6c:	0b 00                	or     (%eax),%eax
 8049f6e:	00 00                	add    %al,(%eax)
 8049f70:	10 00                	adc    %al,(%eax)
 8049f72:	00 00                	add    %al,(%eax)
 8049f74:	15 00 00 00 00       	adc    $0x0,%eax
 8049f79:	00 00                	add    %al,(%eax)
 8049f7b:	00 03                	add    %al,(%ebx)
 8049f7d:	00 00                	add    %al,(%eax)
 8049f7f:	00 00                	add    %al,(%eax)
 8049f81:	a0 04 08 02 00       	mov    0x20804,%al
 8049f86:	00 00                	add    %al,(%eax)
 8049f88:	58                   	pop    %eax
 8049f89:	00 00                	add    %al,(%eax)
 8049f8b:	00 14 00             	add    %dl,(%eax,%eax,1)
 8049f8e:	00 00                	add    %al,(%eax)
 8049f90:	11 00                	adc    %eax,(%eax)
 8049f92:	00 00                	add    %al,(%eax)
 8049f94:	17                   	pop    %ss
 8049f95:	00 00                	add    %al,(%eax)
 8049f97:	00 9c 83 04 08 11 00 	add    %bl,0x110804(%ebx,%eax,4)
 8049f9e:	00 00                	add    %al,(%eax)
 8049fa0:	8c 83 04 08 12 00    	mov    %es,0x120804(%ebx)
 8049fa6:	00 00                	add    %al,(%eax)
 8049fa8:	10 00                	adc    %al,(%eax)
 8049faa:	00 00                	add    %al,(%eax)
 8049fac:	13 00                	adc    (%eax),%eax
 8049fae:	00 00                	add    %al,(%eax)
 8049fb0:	08 00                	or     %al,(%eax)
 8049fb2:	00 00                	add    %al,(%eax)
 8049fb4:	fe                   	(bad)  
 8049fb5:	ff                   	(bad)  
 8049fb6:	ff 6f 6c             	ljmp   *0x6c(%edi)
 8049fb9:	83 04 08 ff          	addl   $0xffffffff,(%eax,%ecx,1)
 8049fbd:	ff                   	(bad)  
 8049fbe:	ff 6f 01             	ljmp   *0x1(%edi)
 8049fc1:	00 00                	add    %al,(%eax)
 8049fc3:	00 f0                	add    %dh,%al
 8049fc5:	ff                   	(bad)  
 8049fc6:	ff 6f 4e             	ljmp   *0x4e(%edi)
 8049fc9:	83 04 08 00          	addl   $0x0,(%eax,%ecx,1)
	...

Disassembly of section .got:

08049ffc <.got>:
 8049ffc:	00 00                	add    %al,(%eax)
	...

Disassembly of section .got.plt:

0804a000 <_GLOBAL_OFFSET_TABLE_>:
 804a000:	14 9f                	adc    $0x9f,%al
 804a002:	04 08                	add    $0x8,%al
	...
 804a00c:	36 84 04 08          	test   %al,%ss:(%eax,%ecx,1)
 804a010:	46                   	inc    %esi
 804a011:	84 04 08             	test   %al,(%eax,%ecx,1)
 804a014:	56                   	push   %esi
 804a015:	84 04 08             	test   %al,(%eax,%ecx,1)
 804a018:	66 84 04 08          	data16 test %al,(%eax,%ecx,1)
 804a01c:	76 84                	jbe    8049fa2 <_DYNAMIC+0x8e>
 804a01e:	04 08                	add    $0x8,%al
 804a020:	86 84 04 08 96 84 04 	xchg   %al,0x4849608(%esp,%eax,1)
 804a027:	08 a6 84 04 08 b6    	or     %ah,-0x49f7fb7c(%esi)
 804a02d:	84 04 08             	test   %al,(%eax,%ecx,1)
 804a030:	c6 84 04 08 d6 84 04 	movb   $0x8,0x484d608(%esp,%eax,1)
 804a037:	08 

Disassembly of section .data:

0804a038 <__data_start>:
 804a038:	00 00                	add    %al,(%eax)
	...

0804a03c <__dso_handle>:
 804a03c:	00 00                	add    %al,(%eax)
	...

Disassembly of section .bss:

0804a040 <stdin@@GLIBC_2.0>:
 804a040:	00 00                	add    %al,(%eax)
	...

0804a044 <completed.7200>:
 804a044:	00 00                	add    %al,(%eax)
	...

0804a048 <main_account>:
 804a048:	00 00                	add    %al,(%eax)
	...

0804a04c <memo>:
 804a04c:	00 00                	add    %al,(%eax)
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	47                   	inc    %edi
   1:	43                   	inc    %ebx
   2:	43                   	inc    %ebx
   3:	3a 20                	cmp    (%eax),%ah
   5:	28 55 62             	sub    %dl,0x62(%ebp)
   8:	75 6e                	jne    78 <_init-0x804837c>
   a:	74 75                	je     81 <_init-0x8048373>
   c:	20 35 2e 34 2e 30    	and    %dh,0x302e342e
  12:	2d 36 75 62 75       	sub    $0x75627536,%eax
  17:	6e                   	outsb  %ds:(%esi),(%dx)
  18:	74 75                	je     8f <_init-0x8048365>
  1a:	31 7e 31             	xor    %edi,0x31(%esi)
  1d:	36 2e 30 34 2e       	ss xor %dh,%cs:(%esi,%ebp,1)
  22:	34 29                	xor    $0x29,%al
  24:	20 35 2e 34 2e 30    	and    %dh,0x302e342e
  2a:	20 32                	and    %dh,(%edx)
  2c:	30 31                	xor    %dh,(%ecx)
  2e:	36 30 36             	xor    %dh,%ss:(%esi)
  31:	30 39                	xor    %bh,(%ecx)
	...
