#ifndef __PAYMENT_SERVICE_H
#define __PAYMENT_SERVICE_H

int payment_add_fine(float amount, int member_id);
int payment_add_fees(int member_id);

#endif