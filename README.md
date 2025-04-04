## Ejemplo de Uso

Este es un ejemplo básico de cómo utilizar las funciones de codificación y decodificación con estructuras personalizadas.

---

### Definición de la estructura

1) Define una estructura que contenga todos los datos del mensaje que enviarás/recibirás (codificar y decodificar)
```c
typedef struct {
    uint8_t u_byte;
    uint32_t u_4byte;
    float f;
    char *string;
    char *string_2;
    double d;
} IOT_Message;
```
2) Crea instancias de la estructura como si fuera un contenedor de mensajes
```c
IOT_Message iot_message_decoded;  // Contenedor para datos recibidos
IOT_Message iot_message_encoder;  // Contenedor para datos a enviar
```
3) Crea el formateador o decodificador
```c
Light_Weight_Formatter Specialized_Formatter;
Light_Weight_Decoder Lw_Decoder;
```

3) Crea el formateador o decodificador
```c
LW_Formatter_Init(&Specialized_Formatter);
```
4) Implementar de la siguiente forma:
```c
//Por comodidad utilizo punteros 
uint8_t *decoder_buffer_pointer = Specialized_Formatter.buffer;
size_t decoder_buffer_size = Specialized_Formatter.elements;

LW_Decoder_Init(&Lw_Decoder, decoder_buffer_pointer, decoder_buffer_size);

iot_message_encoder.u_byte = 123 + i * 1000;
iot_message_encoder.u_4byte = 4519871;
iot_message_encoder.string = str;
iot_message_encoder.d = 45133.645987;
iot_message_encoder.f = 3.1415548794;
iot_message_encoder.string_2 = str_2;

LW_Formatter_Restart(&Specialized_Formatter);

LW_Formatter_Add_1_Byte_Unsigned(&Specialized_Formatter, iot_message_encoder.u_byte);
LW_Formatter_Add_4_Byte_Unsigned(&Specialized_Formatter, iot_message_encoder.u_4byte);
LW_Formatter_Add_Float(&Specialized_Formatter, iot_message_encoder.f);
LW_Formatter_Add_Str(&Specialized_Formatter, iot_message_encoder.string, strlen(iot_message_encoder.string) + 1);
LW_Formatter_Add_Double(&Specialized_Formatter, iot_message_encoder.d);
LW_Formatter_Add_Str(&Specialized_Formatter, iot_message_encoder.string_2, strlen(iot_message_encoder.string_2) + 1);

LW_Decoder_Restart(&Lw_Decoder);

iot_message_decoded.u_byte = LW_Decoder_Decode_1_Byte_Unsigned(&Lw_Decoder);
iot_message_decoded.u_4byte = LW_Decoder_Decode_4_Byte_Unsigned(&Lw_Decoder);
iot_message_decoded.f = LW_Decoder_Decode_Float(&Lw_Decoder);
iot_message_decoded.string = LW_Decoder_Decode_String(&Lw_Decoder);
iot_message_decoded.d = LW_Decoder_Decode_Double(&Lw_Decoder);
iot_message_decoded.string_2 = LW_Decoder_Decode_String(&Lw_Decoder);
```
