extern unsigned int gTestValue;
asm("gTestValue = 0x81800000");
extern unsigned int gTestResult;
asm("gTestResult = 0x81800004");
extern unsigned int gTestResult2;
asm("gTestResult2 = 0x8180000C");
extern unsigned int gDebug;
asm("gDebug = 0x81800100");

extern void func_80020024(void);
asm("func_80020024 = 0x80020024");

extern unsigned int TestFunc2(void);
asm("TestFunc2 = 0x82000000");

extern void TestFunc3(void);
asm("TestFunc3 = 0x82C00000");

void TestFunc(void) {
    gDebug = 1;
    gTestResult = gTestValue + 0xBEEF;
    gDebug = 2;
    gTestResult2 = TestFunc2();
    gDebug = 3;
    func_80020024();
    gDebug = 4;
    TestFunc3();
    gDebug = 5;
}
