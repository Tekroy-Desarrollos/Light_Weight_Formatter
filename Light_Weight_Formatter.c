/**
 * @file Light_Weigth_Formatter.c
 * @author Victor Le Roy Brito (vleroy@tekroy.cl)
 * @brief 
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Light_Weight_Formatter.h"

void LW_Formatter_Init(Light_Weight_Formatter * formatter_instance, uint8_t * buffer, size_t buffer_size){
    formatter_instance->elements = 0;
    formatter_instance->buffer = buffer;
    formatter_instance->buffer_size = buffer_size;
}

size_t LW_Formatter_Get_Elements(Light_Weight_Formatter * formatter_instance){
    return formatter_instance->elements;
}

void LW_Formatter_Restart(Light_Weight_Formatter * lw_decoder){
    lw_decoder->elements = 0;
}

size_t LW_Formatter_Add_Data_Starting_At_Index(Light_Weight_Formatter * formatter_instance, uint32_t index, uint8_t * base, size_t bytes_number){
    formatter_instance->elements = index;
    for(uint32_t i = index; i < index + bytes_number; i++){
        formatter_instance->buffer[formatter_instance->elements++] = *base++;
    }
}

void LW_Formatter_Add_Variable_Interface(Light_Weight_Formatter * formatter_instance, uint8_t * base, size_t bytes_number){
    for(uint8_t i = 0; i < bytes_number; i++){
        formatter_instance->buffer[formatter_instance->elements++] = *base++;
    }
}

uint8_t * LW_Formatter_Get_Buffer(Light_Weight_Formatter * formatter_instance){
    return formatter_instance->buffer;
}

void LW_Formatter_Print_Contents(Light_Weight_Formatter * formatter_instance){
    printf("Formatter Buffer Contents: \r\n");

    for(uint8_t i = 0; i < formatter_instance->elements; i++){
        printf("[%02X]", formatter_instance->buffer[formatter_instance->elements - 1 - i]);
    }
    printf("\r\n================");
}

void LW_Formatter_Print_Contents_Hex_Raw(Light_Weight_Formatter * formatter_instance){
    printf("Formatter Buffer Contents: \r\n");

    for(uint8_t i = 0; i < formatter_instance->elements; i++){
        //printf("%02X", formatter_instance->buffer[formatter_instance->elements - 1 - i]);
        printf("%02X", formatter_instance->buffer[i]);
    }
    printf("\r\nBytes Used: %lu", formatter_instance->elements);
    printf("\r\n================\r\n");
}

