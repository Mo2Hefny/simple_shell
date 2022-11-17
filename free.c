#include "main.h"

/**
 * free_item - frees buffer.
 * @buff: buffer.
 */

void free_item(char **buff)
{

if (!buff)
return;

free(buff);
}
