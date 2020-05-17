#include "utils.h"
#include "config.h"

int		is_whitespace(char c)
{
	return (c == '\t'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ');
}

int	is_delimiter(char c)
{
	return (is_whitespace(c)
			|| c == '\0'
			|| c == '\n' 
			|| c == COMMAND_CHAR
			|| c == '\"'
			|| c == DIRECT_CHAR
			|| c == SEPARATOR_CHAR
			|| c == COMMENT_CHAR
			|| c == ALT_COMMENT_CHAR);
}
