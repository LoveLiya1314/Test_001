这是一个关于一些知识的总结文档
=================

## 关于Qt的组件

### Qt 的功能模块，包括用于不同编译器和平台的模块：


	① MinGW 5.3.0 32 bit 编译器模块。MinGW 是 Minimalist GNU for Windows 的缩写，MinGW是 Windows 平台上使用的 GNU 工具集导入库的集合。
	
	② 用于 UWP 编译的模块。UWP 是 Windows 10 中 Universal Windows Platform 的简称，有不同编译器类型的 UWP。
	
	③ 用于 windows 平台上的 MSVC 编译器模块，如 msvc2015 32-bit 和 msvc2015 64-bit 等。要安装 MSVC 编译器的模块，需要计算机上已经安装相应版本的 Visual Studio。
	
	④ 用于 Android 平台的模块，如 Android x86 和 Android ARMv7。
	
	⑤ Sources 模块是 Qt 的源程序。
	
	⑥ Qt Charts 是二维图表模块，用于绘制柱状图、饼图、曲线图等常用二维图表。
	
	⑦ Qt Data Visualization 是三维数据图表模块，用于数据的三维显示，如散点的三维空间分布、三维曲面等。
	
	⑧ Qt Purchasing、Qt WebEngine、Qt Network Auth(TP)等其他模块，括号里的 TP 表示技术预览（Technology Preview）。
	
	⑨ Qt Scritp（Deprecated）是脚本模块，括号里的“Deprecated”表示这是已经过时的模块。

### “Tools”节点下面是一些工具软：
	① Qt Creator 4.3.1 是用于 Qt 程序开发的 IDE。
	② MinGW 5.3.0 是 MinGW 编译工具链。
	③ Strawberry Perl 是一个 Perl 语言工具。

## 关于汇编

### 一些常见指令



*------------------------------------------ 一、数据传输指令 -------------------------------------*

**1. 通用数据传送指令：**

```text
MOV     传送字或字节.  
MOVSX   先符号扩展,再传送.  
MOVZX   先零扩展,再传送.  
PUSH    把字压入堆栈.  
POP     把字弹出堆栈.  
PUSHA   把AX,CX,DX,BX,SP,BP,SI,DI依次压入堆栈.  
POPA    把DI,SI,BP,SP,BX,DX,CX,AX依次弹出堆栈.  
PUSHAD  把EAX,ECX,EDX,EBX,ESP,EBP,ESI,EDI依次压入堆栈.  
POPAD   把EDI,ESI,EBP,ESP,EBX,EDX,ECX,EAX依次弹出堆栈.  
BSWAP   交换32位寄存器里字节的顺序  
XCHG    交换字或字节.(至少有一个操作数为寄存器,段寄存器不可作为操作数)  
CMPXCHG 比较并交换操作数.(第二个操作数必须为累加器AL/AX/EAX)  
XADD    先交换再累加.(结果在第一个操作数里)  
XLAT    字节查表转换.----BX指向一张256字节的表的起点,
        AL为表的索引值(0-255,即0-FFH);
        返回AL为查表结果.([BX+AL]->AL)  
```

**2. 输入输出端口传送指令:**

```text
IN      I/O端口输入. ( 语法: IN   累加器,    {端口号│DX} )  
OUT     I/O端口输出. ( 语法: OUT {端口号│DX},累加器 )
                    输入输出端口由立即方式指定时,其范围是 0-255; 
                    由寄存器 DX 指定时,其范围是 0-65535.  
```

**3. 目的地址传送指令:**

```text
LEA     装入有效地址.例: LEA DX,string ;把偏移地址存到DX.  
LDS     传送目标指针,把指针内容装入DS.例: LDS SI,string ;把段地址:偏移地址存到DS:SI.  
LES     传送目标指针,把指针内容装入ES.例: LES DI,string ;把段地址:偏移地址存到ES:DI.  
LFS     传送目标指针,把指针内容装入FS.例: LFS DI,string ;把段地址:偏移地址存到FS:DI.  
LGS     传送目标指针,把指针内容装入GS.例: LGS DI,string ;把段地址:偏移地址存到GS:DI.  
LSS     传送目标指针,把指针内容装入SS.例: LSS DI,string ;把段地址:偏移地址存到SS:DI.  
```

**4. 标志传送指令:**

```text
LAHF    标志寄存器传送,把标志装入AH.  
SAHF    标志寄存器传送,把AH内容装入标志寄存器.  
PUSHF   标志入栈.  
POPF    标志出栈.  
PUSHD   32位标志入栈.  
POPD    32位标志出栈.  
```

*------------------------------------------- 二、算术运算指令 ------------------------------------*

```text
ADD     加法.  
ADC     带进位加法.  
INC     加 1.  
AAA     加法的ASCII码调整.  
DAA     加法的十进制调整.  
SUB     减法.  
SBB     带借位减法.  
DEC     减 1.  
NEG     求反(以    0 减之).  
CMP     比较.(两操作数作减法,仅修改标志位,不回送结果).  
AAS     减法的ASCII码调整.  
DAS     减法的十进制调整.  
MUL     无符号乘法.结果回送AH和AL(字节运算),或DX和AX(字运算),  
IMUL    整数乘法.结果回送AH和AL(字节运算),或DX和AX(字运算),  
AAM     乘法的ASCII码调整.  
DIV     无符号除法.结果回送:商回送AL,余数回送AH, (字节运算);或 商回送AX,余数回送DX, (字运算).  
IDIV    整数除法.结果回送:商回送AL,余数回送AH, (字节运算);或 商回送AX,余数回送DX, (字运算).  
AAD     除法的ASCII码调整.  
CBW     字节转换为字. (把AL中字节的符号扩展到AH中去)  
CWD     字转换为双字. (把AX中的字的符号扩展到DX中去)  
CWDE    字转换为双字. (把AX中的字符号扩展到EAX中去)  
CDQ     双字扩展. (把EAX中的字的符号扩展到EDX中去)  

DS:SI   源串段寄存器 :源串变址.  
ES:DI   目标串段寄存器:目标串变址.  
CX      重复次数计数器.  
AL/AX   扫描值.  
D标志    0表示重复操作中SI和DI应自动增量; 1表示应自动减量.  
Z标志    用来控制扫描或比较操作的结束.  
```

*------------------------------------------ 三、逻辑运算指令 ---------------------------------------------*

```text
  AND     与运算.  
    OR      或运算.  
    XOR     异或运算.  
    NOT     取反.  
    TEST    测试.(两操作数作与运算,仅修改标志位,不回送结果).  
    SHL     逻辑左移.  
    SAL     算术左移.(=SHL)  
    SHR     逻辑右移.  
    SAR     算术右移.(=SHR)  
    ROL     循环左移.  
    ROR     循环右移.  
    RCL     通过进位的循环左移.  
    RCR     通过进位的循环右移.  
              以上八种移位指令,其移位次数可达255次.  
              移位一次时, 可直接用操作码. 如 SHL AX,1.  
              移位>1次时, 则由寄存器CL给出移位次数.  
              如 MOV CL,04   SHL AX,CL  
```

*------------------------------------------------ 四、串指令 -----------------------------------------------*

```text
  MOVS    串传送.( MOVSB 传送字符. MOVSW 传送字. MOVSD 传送双字. )  
    CMPS    串比较.( CMPSB 比较字符. CMPSW 比较字. )  
    SCAS    串扫描.把AL或AX的内容与目标串作比较,比较结果反映在标志位.  
    LODS    装入串.把源串中的元素(字或字节)逐一装入AL或AX中.
            ( LODSB 传送字符. LODSW 传送字.    LODSD 传送双字. )  
    STOS    保存串.是LODS的逆过程.  
    REP         当CX/ECX<>0时重复.  
    REPE/REPZ   当ZF=1或比较结果相等,且CX/ECX<>0时重复.  
    REPNE/REPNZ 当ZF=0或比较结果不相等,且CX/ECX<>0时重复.  
    REPC        当CF=1且CX/ECX<>0时重复.  
    REPNC       当CF=0且CX/ECX<>0时重复.  
```

*----------------------------------------- 五、程序转移指令 ----------------------------------------------*

**1. 无条件转移指令 (长转移)**

```text
    JMP         无条件转移指令  
    CALL        过程调用  
    RET/RETF    过程返回
```

**2. 条件转移指令 (短转移,-128到+127的距离内)( 当且仅当(SF XOR OF)=1时,OP1<OP2 )**

```text
  JA/JNBE     不小于或不等于时转移.  
    JAE/JNB     大于或等于转移.  
    JB/JNAE     小于转移.  
    JBE/JNA     小于或等于转移.  
        以上四条,测试无符号整数运算的结果(标志C和Z).  
    JG/JNLE     大于转移.  
    JGE/JNL     大于或等于转移.  
    JL/JNGE     小于转移.  
    JLE/JNG     小于或等于转移.  
        以上四条,测试带符号整数运算的结果(标志S,O和Z).  
    JE/JZ       等于转移.  
    JNE/JNZ     不等于时转移.  
    JC          有进位时转移.  
    JNC         无进位时转移.  
    JNO         不溢出时转移.  
    JNP/JPO     奇偶性为奇数时转移.  
    JNS         符号位为 "0" 时转移.  
    JO          溢出转移.  
    JP/JPE      奇偶性为偶数时转移.  
    JS          符号位为 "1" 时转移.  
```

**3. 循环控制指令(短转移)**

```text
   LOOP            CX不为零时循环.  
    LOOPE/LOOPZ     CX不为零且标志Z=1时循环.  
    LOOPNE/LOOPNZ   CX不为零且标志Z=0时循环.  
    JCXZ            CX为零时转移.  
    JECXZ           ECX为零时转移.  
```

**4. 中断指令**

```text
 INT         中断指令  
    INTO        溢出中断  
    IRET        中断返回  
```

**5. 处理器控制指令**

```text
   HLT         处理器暂停,  直到出现中断或复位信号才继续.  
    WAIT        当芯片引线TEST为高电平时使CPU进入等待状态.  
    ESC         转换到外处理器.  
    LOCK        封锁总线.  
    NOP         空操作.  
    STC         置进位标志位.  
    CLC         清进位标志位.  
    CMC         进位标志取反.  
    STD         置方向标志位.  
    CLD         清方向标志位.  
    STI         置中断允许位.  
    CLI         清中断允许位.  
```

*--------------------------------------------- 六、伪指令 --------------------------------------------------*

```text
  DW          定义字(2字节).  
    PROC        定义过程.  
    ENDP        过程结束.  
    SEGMENT     定义段.  
    ASSUME      建立段寄存器寻址.  
    ENDS        段结束.  
    END         程序结束.  
```

*--------------------------------- 七、处理机控制指令：标志处理指令 ---------------------------------*

```text
 CLC     进位位置0指令  
    CMC     进位位求反指令  
    STC     进位位置为1指令  
    CLD     方向标志置1指令  
    STD     方向标志位置1指令  
    CLI     中断标志置0指令  
    STI     中断标志置1指令  
    NOP     无操作  
    HLT     停机  
    WAIT    等待  
    ESC     换码  
    LOCK    封锁  
```

***====================== 浮点运算指令集========================***

*----------- 一、控制指令(带9B的控制指令前缀F变为FN时浮点不检查，机器码去掉9B)----------*

```text
                                                 机器码
FINIT                 初始化浮点部件              9B DB E3  
FCLEX                 清除异常                   9B DB E2  
FDISI                 浮点检查禁止中断             9B DB E1  
FENI                  浮点检查禁止中断二           9B DB E0  
WAIT                  同步CPU和FPU               9B  
FWAIT                 同步CPU和FPU               D9 D0  
FNOP                  无操作                     DA E9  
FXCH                  交换ST(0)和ST(1)           D9 C9  
FXCH ST(i)            交换ST(0)和ST(i)           D9 C1iii  
FSTSW ax              状态字到ax                 9B DF E0  
FSTSW   word ptr mem  状态字到mem                9B DD mm111mmm  
FLDCW   word ptr mem  mem到状态字                D9 mm101mmm  
FSTCW   word ptr mem  控制字到mem                9B D9 mm111mmm  
  
FLDENV  word ptr mem  mem到全环境                D9 mm100mmm  
FSTENV  word ptr mem  全环境到mem                9B D9 mm110mmm  
FRSTOR  word ptr mem  mem到FPU状态               DD mm100mmm  
FSAVE   word ptr mem  FPU状态到mem               9B DD mm110mmm  
  
FFREE ST(i)           标志ST(i)未使用             DD C0iii  
FDECSTP               减少栈指针1->0 2->1         D9 F6  
FINCSTP               增加栈指针0->1 1->2         D9 F7  
FSETPM                浮点设置保护                 DB E4  
```

*----------------------------------------- 二、数据传送指令 --------------------------------------------*

```text
FLDZ                  将0.0装入ST(0)                  机器码  D9 EE  
FLD1                  将1.0装入ST(0)                  机器码  D9 E8  
FLDPI                 将π装入ST(0)                    机器码  D9 EB  
FLDL2T                将ln10/ln2装入ST(0)             机器码  D9 E9  
FLDL2E                将1/ln2装入ST(0)                机器码  D9 EA  
FLDLG2                将ln2/ln10装入ST(0)             机器码  D9 EC  
FLDLN2                将ln2装入ST(0)                  机器码  D9 ED  
  
FLD    real4 ptr mem  装入mem的单精度浮点数             机器码  D9 mm000mmm  
FLD    real8 ptr mem  装入mem的双精度浮点数             机器码  DD mm000mmm  
FLD   real10 ptr mem  装入mem的十字节浮点数             机器码  DB mm101mmm  
  
FILD    word ptr mem  装入mem的二字节整数              机器码  DF mm000mmm  
FILD   dword ptr mem  装入mem的四字节整数              机器码  DB mm000mmm  
FILD   qword ptr mem  装入mem的八字节整数              机器码  DF mm101mmm  
  
FBLD   tbyte ptr mem  装入mem的十字节BCD数            机器码  DF mm100mmm  
  
FST    real4 ptr mem  保存单精度浮点数到mem             机器码  D9 mm010mmm  
FST    real8 ptr mem  保存双精度浮点数到mem             机器码  DD mm010mmm  
  
FIST    word ptr mem  保存二字节整数到mem              机器码  DF mm010mmm  
FIST   dword ptr mem  保存四字节整数到mem              机器码  DB mm010mmm  
  
FSTP   real4 ptr mem  保存单精度浮点数到mem并出栈      机器码  D9 mm011mmm  
FSTP   real8 ptr mem  保存双精度浮点数到mem并出栈      机器码  DD mm011mmm  
FSTP  real10 ptr mem  保存十字节浮点数到mem并出栈      机器码  DB mm111mmm  
  
FISTP   word ptr mem  保存二字节整数到mem并出栈           机器码  DF mm011mmm  
FISTP  dword ptr mem  保存四字节整数到mem并出栈           机器码  DB mm011mmm  
FISTP  qword ptr mem  保存八字节整数到mem并出栈           机器码  DF mm111mmm  
  
FBSTP  tbyte ptr mem  保存十字节BCD数到mem并出栈     机器码  DF mm110mmm  
  
FCMOVB                ST(0),ST(i) <时传送              机器码  DA C0iii  
FCMOVBE               ST(0),ST(i) <=时传送             机器码  DA D0iii  
FCMOVE                ST(0),ST(i) =时传送             机器码  DA C1iii  
FCMOVNB               ST(0),ST(i) >=时传送             机器码  DB C0iii  
FCMOVNBE              ST(0),ST(i) >时传送              机器码  DB D0iii  
FCMOVNE               ST(0),ST(i) !=时传送            机器码  DB C1iii  
FCMOVNU               ST(0),ST(i) 有序时传送        机器码  DB D1iii  
FCMOVU                ST(0),ST(i) 无序时传送        机器码  DA D1iii  
```

*----------------------------------------------- 三、比较指令 ---------------------------------------------*

```text
FCOM                  ST(0)-ST(1)                         机器码  D8 D1  
FCOMI                 ST(0),ST(i)  ST(0)-ST(1)            机器码  DB F0iii  
FCOMIP                ST(0),ST(i)  ST(0)-ST(1)并出栈      机器码  DF F0iii  
FCOM   real4 ptr mem  ST(0)-实数mem                       机器码  D8 mm010mmm  
FCOM   real8 ptr mem  ST(0)-实数mem                       机器码  DC mm010mmm  
  
FICOM   word ptr mem  ST(0)-整数mem                       机器码  DE mm010mmm  
FICOM  dword ptr mem  ST(0)-整数mem                       机器码  DA mm010mmm  
FICOMP  word ptr mem  ST(0)-整数mem并出栈                 机器码  DE mm011mmm  
FICOMP dword ptr mem  ST(0)-整数mem并出栈                 机器码  DA mm011mmm  
  
FTST                  ST(0)-0                             机器码  D9 E4  
FUCOM  ST(i)          ST(0)-ST(i)                         机器码  DD E0iii  
FUCOMP ST(i)          ST(0)-ST(i)并出栈                   机器码  DD E1iii  
FUCOMPP               ST(0)-ST(1)并二次出栈               机器码  DA E9  
FXAM                  ST(0)规格类型                       机器码  D9 E5  
```

*---------------------------------------------- 四、运算指令 --------------------------------------------*

```text
FADD                  把目的操作数 (直接接在指令后的变量或堆栈缓存器) 与来源操作数 
                      (接在目的操作数后的变量或堆栈缓存器)  相加，并将结果存入目的操作数  
FADDP  ST(i),ST       这个指令是使目的操作数加上 ST  缓存器，并弹出 ST 缓存器，
                      而目的操作数必须是堆栈缓存器的其中之一，最后不管目的操作数为何，
                      经弹出一次后，目的操作数会变成上一个堆栈缓存器了  
FIADD                 FIADD 是把 ST   加上来源操作数，然后再存入 ST 缓存器，
                      来源操作数必须是字组整数或短整数形态的变数  
FSUB                  减  
FSUBP
FSUBR                 减数与被减数互换  
FISUB  
FISUBR 
FMUL                  乘  
FMULP  
FIMUL 
FDIV                  除  
FDIVP  
FDIVR  
FDIVRP  
FIDIV  
FIDIVR 
FCHS                  改变 ST 的正负值  
  
FABS                  把 ST  之值取出，取其绝对值后再存回去。  
  
FSQRT                 将 ST  之值取出，开根号后再存回去。  
  
FSCALE                这个指令是计算 ST*2^ST(1)之值，再把结果存入ST里，而 ST(1)之值不变
                      ST(1)必须是在 -32768 到 32768(-215到215)之间的整数，
                      如果超过这个范围计算结果无法确定，如果不是整数ST(1)会先向零舍入成整数
                      再计算。所以为安全起见，最好是由字组整数载入到 ST(1) 里。  
  
FRNDINT               这个指令是把 ST 的数值舍入成整数，FPU提供四种舍入方式，
                      由 FPU 的控制字组(control word)中的RC两个位决定  
                      	  RC    舍入控制  
                          00    四舍五入  
                          01    向负无限大舍入  
                          10    向正无限大舍入  
                          11    向零舍去  
```

### 关于寄存器

通用寄存器可用于传送和暂存数据，也可参与算术逻辑运算，并保存运算结果。八个寄存器都可以作为普通的数据寄存器使用。（共同功能）

16位cpu通用寄存器共有　8　个： ***\*AX,   BX,   CX,   DX,\**       \**BP,   SP,\**      \**SI,   DI.\****

32位cpu通用寄存器共有　8　个： ***\*EAX,  EBX,  ECX, EDX,\**     \**EBP,  ESP,\**     \**ESI,  EDI\**  \**\*\*(E表示Extended)\*\**\*** 

***\*数据寄存器\**   \**\*\*EAX,  EBX,  ECX, EDX,\*\*    \*\*\*\*(Data Register)\*\*\*\*\****
数据寄存器主要用来保存操作数和运算结果等信息，从而节省读取操作数所需占用总线和访问存储器的时间。 
　　32位CPU有4个32位的通用寄存器EAX、EBX、ECX和EDX。对低16位数据的存取，不会影响高16位的数据。这些低16位寄存器分别命名为：AX、BX、CX和DX，它和先前的CPU中的寄存器相一致。
4个16位寄存器又可分割成8个独立的8位寄存器(AX：AH-AL、BX：BH-BL、CX：CH-CL、DX：DH-DL)，每个寄存器都有自己的名称，可独立存取。程序员可利用数据寄存器的这种“可分可合”的特性，灵活地处理字/字节的信息。
寄存器AX通常称为**累加器(Accumulator)**，用累加器进行的操作可能需要更少时间。累加器可用于乘、除、输入/输出等操作，它们的使用频率很高； 

寄存器BX称为**基地址寄存器(Base Register)**。它可作为存储器指针来使用； 

寄存器CX称为**计数寄存器(Count Register)**。在循环和字符串操作时，要用它来控制循环次数；在位操作中，当移多位时，要用CL来指明移位的位数； 

寄存器DX称为**数据寄存器(Data Register)**。在进行乘、除运算时，它可作为默认的操作数参与运算，也可用于存放I/O的端口地址。

***\*指针寄存器\**  \**\*\*EBP,  ESP，\*\*            \*\*\*\*(Pointer Register)\*\*\*\*\****
32位CPU有2个32位通用寄存器EBP和ESP。其低16位对应先前CPU中的SBP和SP，对低16位数据的存取，不影响高16位的数据。

指针寄存器主要用于存放堆栈内存储单元的偏移量，用它们可实现多种存储器操作数的寻址方式(在第3章有详细介绍)，为以不同的地址形式访问存储单元提供方便。指针寄存器不可分割成8位寄存器。作为通用寄存器，也可存储算术逻辑运算的操作数和运算结果。

寄存器BP称为**基址指针寄存器（Base Pointer）**；

寄存器SP称为**堆栈指针寄存器（Stack Pointer）**。

**变址寄存器  \**ESI,  EDI ，             \*\*(Index Register)\*\**\***
32位CPU有2个32位通用寄存器ESI和EDI。其低16位对应先前CPU中的SI和DI，对低16位数据的存取，不影响高16位的数据。

变址寄存器主要用于存放存储单元在段内的偏移量，用它们可实现多种存储器操作数的寻址方式(在第3章有详细介绍)，为以不同的地址形式访问存储单元提供方便。 变址寄存器不可分割成8位寄存器。作为通用寄存器，也可存储算术逻辑运算的操作数和运算结果。
寄存器SI称为**源变址寄存器 （Source Index）；**

寄存器DI称为**目的变址寄存器（Destination Index）。**

## 附：MS-DOS命令行相关常用命令

	 dir (directory) ：列出当前目录下的文件以及文件夹
	 md (make directory)： 创建目录
	 rd (remove directory)：删除目录
	 cd (change directory)：进入指定目录
	 cd.. : 退回到上一级目录
	 cd\ : 退回到根目录
	 del：删除文件
	 exit：退出dos命令行
	 cls (clear screen): 清屏
	 ### 有关某个命令的详细信息，请键入 HELP 命令名
	 ASSOC 显示或修改文件扩展名关联。
	 ATTRIB 显示或更改文件属性。
	 BREAK 设置或清除扩展式 CTRL+C 检查。
	 BCDEDIT 设置启动数据库中的属性以控制启动加载。
	 CACLS 显示或修改文件的访问控制列表(ACL)。
	 CALL 从另一个批处理程序调用这一个。
	 CD 显示当前目录的名称或将其更改。
	 CHCP 显示或设置活动代码页数。
	 CHDIR 显示当前目录的名称或将其更改。
	 CHKDSK 检查磁盘并显示状态报告。
	 CHKNTFS 显示或修改启动时间磁盘检查。
	 CLS 清除屏幕。
	 CMD 打开另一个 Windows 命令解释程序窗口。
	 COLOR 设置默认控制台前景和背景颜色。
	 COMP 比较两个或两套文件的内容。
	 COMPACT 显示或更改 NTFS 分区上文件的压缩。
	 CONVERT 将 FAT 卷转换成 NTFS。您不能转换当前驱动器。
	 COPY 将至少一个文件复制到另一个位置。
	 DATE 显示或设置日期。
	 DEL 删除至少一个文件。
	 DIR 显示一个目录中的文件和子目录。
	 DISKCOMP 比较两个软盘的内容。
	 DISKCOPY 将一个软盘的内容复制到另一个软盘。
	 DISKPART 显示或配置磁盘分区属性。
	 DOSKEY 编辑命令行、调用 Windows 命令并创建宏。
	 DRIVERQUERY 显示当前设备驱动程序状态和属性。
	 ECHO 显示消息，或将命令回显打开或关上。
	 ENDLOCAL 结束批文件中环境更改的本地化。
	 ERASE 删除一个或多个文件。
	 EXIT 退出 CMD.EXE 程序(命令解释程序)。
	 FC 比较两个文件或两个文件集并显示它们之间的不同。
	 FIND 在一个或多个文件中搜索一个文本字符串。
	 FINDSTR 在多个文件中搜索字符串。
	 FOR 为一套文件中的每个文件运行一个指定的命令。
	 FORMAT 格式化磁盘，以便跟 Windows 使用。
	 FSUTIL 显示或配置文件系统的属性。
	 FTYPE 显示或修改用在文件扩展名关联的文件类型。
	 GOTO 将 Windows 命令解释程序指向批处理程序中某个带标签的行。
	 GPRESULT 显示机器或用户的组策略信息。
	 GRAFTABL 启用 Windows 在图形模式显示扩展字符集。
	 HELP 提供 Windows 命令的帮助信息。
	 ICACLS 显示、修改、备份或还原文件和目录的 ACL。
	 IF 在批处理程序中执行有条件的处理过程。
	 LABEL 创建、更改或删除磁盘的卷标。
	 MD 创建一个目录。
	 MKDIR 创建一个目录。
	 MKLINK 创建符号链接和硬链接
	 MODE 配置系统设备。
	 MORE 逐屏显示输出。
	 MOVE 将一个或多个文件从一个目录移动到另一个目录。
	 OPENFILES 显示远程用户为了文件共享而打开的文件。
	 PATH 为可执行文件显示或设置搜索路径。
	 PAUSE 停止批处理文件的处理并显示信息。
	 POPD 还原由 PUSHD 保存的当前目录上一次的值。
	 PRINT 打印一个文本文件。
	 PROMPT 改变 Windows 命令提示。
	 PUSHD 保存当前目录，然后对其进行更改。
	 RD 删除目录。
	 RECOVER 从损坏的磁盘中恢复可读取的信息。
	 REM 记录批处理文件或 CONFIG.SYS 中的注释。
	 REN 重新命名文件。
	 RENAME 重新命名文件。
	 REPLACE 替换文件。
	 RMDIR 删除目录。
	 ROBOCOPY 复制文件和目录树的高级实用程序
	 SET 显示、设置或删除 Windows 环境变量。
	 SETLOCAL 开始用批文件改变环境的本地化。
	 SC 显示或配置服务(后台处理)。
	 SCHTASKS 安排命令和程序在一部计算机上按计划运行。
	 SHIFT 调整批处理文件中可替换参数的位置。
	 SHUTDOWN 让机器在本地或远程正确关闭。
	 SORT 将输入排序。
	 START 打开单独视窗运行指定程序或命令。
	 SUBST 将驱动器号与路径关联。
	 SYSTEMINFO 显示机器的具体的属性和配置。
	 TASKLIST 显示包括服务的所有当前运行的任务。
	 TASKKILL 终止正在运行的进程或应用程序。
	 TIME 显示或设置系统时间。
	 TITLE 设置 CMD.EXE 会话的窗口标题。
	 TREE 以图形显示启动器或路径的目录结构。
	 TYPE 显示文本文件的内容。
	 VER 显示 Windows 的版本。
	 VERIFY 告诉 Windows 验证文件是否正确写入磁盘。
	 VOL 显示磁盘卷标和序列号。
	 XCOPY 复制文件和目录树。
	 WMIC 在交互命令外壳里显示 WMI 信息。
