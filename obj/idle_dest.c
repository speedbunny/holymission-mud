/* Matt Jan-13-95: Destructs idle players every reset */

#define MAX_IDLE 1200
#define LOG_FILE "IDLERS"

int id(string str);
void dest_idlers();
int player_filt(object obj);
string query_name();

int id(string str) { return str == "idle_dest"; }

int no_clean_up() {
    return 1;
}

void reset(int arg) {
  dest_idlers();
}

void dest_idlers() {
  int i;
  object *players;

  players = filter_array(users(), "player_filt", this_object());
  for(i = 0; i < sizeof(players); i++) {
    if(!players[i]) continue;
    if(query_idle(players[i]) > MAX_IDLE) {
      tell_object(players[i],
		  "You have been idle for too long. Destructing...");
      log_file(LOG_FILE, capitalize(players[i]->query_real_name()) +
	       " destructed on " + ctime(time()) + " with idle time of " +
	       query_idle(players[i]) + " sec.\n");
      destruct(players[i]);
    }
  }
}

int player_filt(object obj) {
  return !obj->query_immortal();
}
