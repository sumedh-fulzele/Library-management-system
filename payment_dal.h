#ifndef __PAYMENT_DAL_H
#define __PAYMENT_DAL_H

#include"payment.h"

int payment_save(payment_t *p);
int get_max_pay_id();
int payment_search_by_id(int payment_id, payment_t *p);

#endif