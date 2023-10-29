/*
 * bit_math.h
 *
 * Created: 20/10/2023 12:07:09 م
 *  Author: Dell
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,POS)       (REG |= (BIT_MASK << POS))
#define CLEAR_BIT(REG,POS)     (REG &= ~(BIT_MASK << POS))
#define TOGGL_EBIT(REG,POS)    (REG ^= (BIT_MASK << POS))
#define READ_BIT(REG,POS)      ((REG >> POS) & BIT_MASK)
#define FLIP_BIT(REG,POS)      (REG ^= (BIT_MASK << POS))




#endif /* BIT_MATH_H_ */