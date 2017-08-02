#include <argp.h>
#include <stdbool.h>

const char *argp_program_version = "lsu 0.1";
const char *argp_program_bug_address = "<xuehao.hu@gmail.com>";
static char doc[] = "\nlsu (named after \"list util\") is a linux util that lists and categorizes existing utils on linux machine. Serves as a starting point for discovering installed utils on current box.\n";
static char args_doc[] = "[FILENAME]...";
static struct argp_option options[] = { 
	{ "line", 'l', 0, 0, "Compare lines instead of characters."},
	{ "word", 'w', 0, 0, "Compare words instead of characters."},
	{ "nocase", 'i', 0, 0, "Compare case insensitive instead of case sensitive."},
	{ 0 }
};

struct arguments {
	enum { CHARACTER_MODE, WORD_MODE, LINE_MODE } mode;
	bool isCaseInsensitive;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
	struct arguments *arguments = state->input;
	switch (key) {
		case 'l': arguments->mode = LINE_MODE; break;
		case 'w': arguments->mode = WORD_MODE; break;
		case 'i': arguments->isCaseInsensitive = true; break;
		case ARGP_KEY_ARG: return 0;
		default: return ARGP_ERR_UNKNOWN;
	}   
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char *argv[])
{
	struct arguments arguments;

	arguments.mode = CHARACTER_MODE;
	arguments.isCaseInsensitive = false;

	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	// ...
}
