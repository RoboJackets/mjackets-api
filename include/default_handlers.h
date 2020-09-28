#ifndef _DEFAULT_HANDLERS_H
#define _DEFAULT_HANDLERS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  Infinite loop event handler
  * @retval None
  */
void Handler_Loop(void);

/**
  * @brief  Do nothing event handler
  * @retval None
  */
void Handler_Nothing(void);

/**
  * @brief  Error handler
  * @retval None
  */
void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif //_DEFAULT_HANDLERS_H