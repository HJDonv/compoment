#ifndef D_KFIFO_H_
#define D_KFIFO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "string.h"

#define min(a, b)                (((a) < (b)) ? (a) : (b))

#define D_KFIFO_CRITICAL_REGION_ENTER()
#define D_KFIFO_CRITICAL_REGION_EXIT() 

typedef struct 
{   
    uint8_t *p_buffer;          /* the buffer holding the data */   
    uint32_t size;              /* the size of the allocated buffer */   
    uint32_t in;                /* data is added at offset (in % size) */   
    uint32_t out;               /* data is extracted from off. (out % size) */
    uint32_t mask;
} d_kfifo_t;

uint32_t d_kfifo_init(d_kfifo_t *d_kfifo, uint8_t *p_buffer, uint32_t size);
uint32_t d_kfifo_deinit(d_kfifo_t *d_kfifo);
uint32_t d_kfifo_in(d_kfifo_t *d_kfifo, uint8_t *p_buffer, uint32_t len);
uint32_t d_kfifo_out(d_kfifo_t *d_kfifo, uint8_t *p_buffer, uint32_t len);
uint32_t d_kfifo_len(d_kfifo_t *d_kfifo); /* 返回队列中已经存在的个数 */
uint32_t d_kfifo_avail(d_kfifo_t *d_kfifo); /* 返回队列没有被使用的个数 */
uint32_t d_kfifo_is_empty(d_kfifo_t *d_kfifo);
uint32_t d_kfifo_is_full(d_kfifo_t *d_kfifo);
uint32_t d_kfifo_put(d_kfifo_t *d_kfifo, uint8_t  val);
uint32_t d_kfifo_get(d_kfifo_t *d_kfifo, uint8_t *val);
uint32_t d_kfifo_peek_out(d_kfifo_t *d_kfifo, uint8_t *p_buffer, uint32_t len, uint32_t offset); /* offset指的是偏移out的距离 */
uint32_t d_kfifo_flush(d_kfifo_t *d_kfifo);



#ifdef __cplusplus
}
#endif

#endif
