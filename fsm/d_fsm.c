#include "d_fsm.h"



/* 构建状态机实例 */
uint32_t d_fsm_init(d_fsm_t *p_fsm, d_fsm_table_elem_t *p_fsm_table, uint32_t table_elems, uint32_t init_sta)
{
    if (p_fsm != NULL && p_fsm_table != NULL) {
        p_fsm->p_fsm_table = p_fsm_table;
        p_fsm->table_elems = table_elems;
        p_fsm->cur_sta = init_sta;
    }
    return 0;
}


static inline void d_fsm_trans(d_fsm_t *p_fsm, uint32_t sta)
{
    p_fsm->cur_sta = sta;
}

/* 事件派发 */
uint32_t d_fsm_dispatch(d_fsm_t *p_fsm, uint32_t evt)
{
    if (p_fsm == NULL) { return 0; } 

    /* 轮询table的elment */
    for (uint32_t i = 0; i < p_fsm->table_elems; i++) {

        if (p_fsm->p_fsm_table[i].cur_sta == p_fsm->cur_sta &&
            p_fsm->p_fsm_table[i].evt == evt) {

            /* callback */
            if (p_fsm->p_fsm_table[i].pfn_evt_cb != NULL) {

                p_fsm->p_fsm_table[i].pfn_evt_cb();   
            }

            /* 切换状态 */
            d_fsm_trans(p_fsm, p_fsm->p_fsm_table[i].tar_sta);

            /* 退出循环 */
            break;
        }
    }
    
    return 0;
}


