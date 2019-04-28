#ifndef D_FSM_H_
#define D_FSM_H_


#include <stdint.h>
#include <string.h>

/* 选择状态机的实现方式 */
#define D_FSM_1     1

#if (D_FSM_1 == 1)



/* 组件保留事件id */
enum {
    EVT_USR = 0,
};

/* 组件保留状态id */
enum {
    STA_USR = 0,
};

/* 状态表元素 */
typedef struct {
    uint32_t        evt;
    uint32_t        cur_sta;
    uint32_t        tar_sta;
    void          (*pfn_evt_cb)(void);
} d_fsm_table_elem_t;


/* 状态机实例 */
typedef struct {
    d_fsm_table_elem_t  *p_fsm_table;
    uint32_t             cur_sta;
    uint32_t             table_elems;
} d_fsm_t;


/* 构建状态机实例 */
uint32_t d_fsm_init(d_fsm_t *p_fsm, d_fsm_table_elem_t *p_fsm_table, 
                    uint32_t table_elems, uint32_t init_sta);

/* 事件派发 */
uint32_t d_fsm_dispatch(d_fsm_t *p_fsm, uint32_t evt);

/* 

/* 事件id */
enum {
    EVT_1 = EVT_USR + 1,
    EVT_2 = EVT_USR + 2,
    EVT_3 = EVT_USR + 3,
    EVT_4 = EVT_USR + 4,
};

/* 状态id */
enum {
    STA_1 = STA_USR + 1,
    STA_2 = STA_USR + 2,
    STA_3 = STA_USR + 3,
    STA_4 = STA_USR + 4,
};


void test1()
{
    hj_wl_uart_send("test1\r\n", 7);
}

void test2()
{
    hj_wl_uart_send("test2\r\n", 7);
}
    
void test3()
{
    hj_wl_uart_send("test3\r\n", 7);
}
    
void test4()
{
    hj_wl_uart_send("test4\r\n", 7);
}



d_fsm_table_elem_t demo_table[] = {
    {EVT_1, STA_1, STA_2, test1},
    {EVT_2, STA_2, STA_3, test2},
    {EVT_3, STA_3, STA_4, test3},
    {EVT_4, STA_4, STA_1, test4},
};

d_fsm_t demo_fsm;

d_fsm_init(&demo_fsm, demo_table, sizeof(demo_table) / sizeof(demo_table[0]), STA_1);

/* 事件派发 */
d_fsm_dispatch(&demo_fsm, EVT_1);
d_fsm_dispatch(&demo_fsm, EVT_2);
d_fsm_dispatch(&demo_fsm, EVT_3);
d_fsm_dispatch(&demo_fsm, EVT_4);
*/


#endif /* D_FSM_1 == 1*/




#endif