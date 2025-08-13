# TC264 基础库

本库基于逐飞科技的 TC264 开源库编写。

## 注意事项

类型加上了易变性修饰，避免 O2 优化时空循环被优化。定义如下：

```c
typedef signed char int8;       // 有符号  8 bits
typedef signed short int int16; // 有符号 16 bits
typedef signed int int32;       // 有符号 32 bits
typedef signed long long int64; // 有符号 64 bits

typedef volatile uint8 vuint8;   // 易变性修饰 无符号  8 bits
typedef volatile uint16 vuint16; // 易变性修饰 无符号 16 bits
typedef volatile uint32 vuint32; // 易变性修饰 无符号 32 bits
typedef volatile uint64 vuint64; // 易变性修饰 无符号 64 bits

typedef volatile int8 vint8;   // 易变性修饰 有符号  8 bits
typedef volatile int16 vint16; // 易变性修饰 有符号 16 bits
typedef volatile int32 vint32; // 易变性修饰 有符号 32 bits
typedef volatile int64 vint64; // 易变性修饰 有符号 64 bits
```
