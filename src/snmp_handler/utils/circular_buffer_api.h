#include <stdbool.h>

bool write_data_request_into_message_buffer(message_t** msg_ptr);
bool read_data_request_from_message_buffer(message_t** msg_ptr);

/* Checks whether the circular buffer empty (true) or not (false) */
bool is_circular_buffer_empty();

/* Checks whether the circular buffer full (true) or not (false) */
bool is_circular_buffer_full(); 