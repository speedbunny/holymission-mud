#define SAVE_FILE "/players/warlord/test"

string saved_string;
static string not_saved;

int saved_int;

mapping saved_map;

void save() {
    save_object(SAVE_FILE);
}

string set_not_saved(string str) {
    not_saved=str;
    return not_saved;
}

void reset(int arg) {
    if(arg)
        return;
    if(!restore_object(SAVE_FILE)) {
        saved_string="blah";
        saved_int=8;
        saved_map=(["key":"value"]);
        save();
    }
}
