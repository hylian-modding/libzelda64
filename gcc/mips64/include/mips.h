/*************************************
* MIPS64 General Purpose Header File *
*************************************/
#ifndef __MIPS_H__
#define __MIPS_H__

/*
** Register names according to MIPS ABI

#ifdef __LANGUAGE_ASSEMBLY__*/
#define v0      $2
#define v1      $3
#define a0      $4
#define a1      $5
#define a2      $6
#define a3      $7
#define t0      $8
#define t1      $9
#define t2      $10
#define t3      $11
#define t4      $12
#define t5      $13
#define t6      $14
#define t7      $15
#define s0      $16
#define s1      $17
#define s2      $18
#define s3      $19
#define s4      $20
#define s5      $21
#define s6      $22
#define s7      $23
#define t8      $24
#define t9      $25
#define k0      $26
#define k1      $27
#define s8      $30
/* #endif __LANGUAGE_ASSEMBLY__ */


/*
** Coprocessor 0 registers

#ifdef __LANGUAGE_ASSEMBLY__*/
#define C0_INX          $0
#define C0_RAND         $1
#define C0_ENTRYLO0     $2
#define C0_ENTRYLO1     $3
#define C0_CONTEXT      $4
#define C0_PAGEMASK     $5      /* page mask                        */
#define C0_WIRED        $6      /* # wired entries in tlb           */
#define C0_BADVADDR     $8
#define C0_COUNT        $9      /* free-running counter             */
#define C0_ENTRYHI      $10
#define C0_SR           $12
#define C0_CAUSE        $13
#define C0_EPC          $14
#define C0_PRID         $15     /* revision identifier              */
#define C0_COMPARE      $11     /* counter comparison reg.          */
#define C0_CONFIG       $16     /* hardware configuration           */
#define C0_LLADDR       $17     /* load linked address              */
#define C0_WATCHLO      $18     /* watchpoint                       */
#define C0_WATCHHI      $19     /* watchpoint                       */
#define C0_ECC          $26     /* S-cache ECC and primary parity   */
#define C0_CACHE_ERR    $27     /* cache error status               */
#define C0_TAGLO        $28     /* cache operations                 */
#define C0_TAGHI        $29     /* cache operations                 */
#define C0_ERROR_EPC    $30     /* ECC error prg. counter           

#endif*/



#endif /* __MIPS_H__ */
