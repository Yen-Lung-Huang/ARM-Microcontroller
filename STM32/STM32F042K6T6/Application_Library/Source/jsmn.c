#include "jsmn.h"

int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
	if (tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start &&
			strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}

/* return next token, ignoring descendants */
jsmntok_t *skip_token(jsmntok_t *token)
{
	int pending = 1;
	do {
		pending += token->size - 1;
		token++;
	} while (pending);
	return token;
}

/* find the first member with the given name */
jsmntok_t *object_get_member(const char *json, jsmntok_t *object, const char *name)
{
	if (!object || object->type != JSMN_OBJECT || !name) {
		return NULL;
	}

	int members = object->size;
	jsmntok_t *token = object + 1;
	while (members && jsoneq(json, token, name) != 0) {
		members--;
		token = skip_token(token+1);
	}
	if (!members) {
		return NULL;
	}
	return token + 1;
}

/* find the element at the given position of an array (starting at 0). */
jsmntok_t *array_get_at(jsmntok_t *object, int index)
{
	if (!object || object->type != JSMN_ARRAY || index < 0 
	|| object->size <= index) {
		return NULL;
	}

	jsmntok_t *token = object + 1;
	for (int i = 0; i < index; i++) {
		token = skip_token(token);
	}
	return token;
}

/* type to string */
const char *jsmntype_str(jsmntype_t type)
{
	switch(type) {
	case JSMN_UNDEFINED: return "UNDEFINED";
	case JSMN_OBJECT: return "OBJECT";
	case JSMN_ARRAY: return "ARRAY";
	case JSMN_STRING: return "STRING";
	case JSMN_PRIMITIVE: return "PRIMITIVE";
	}
}