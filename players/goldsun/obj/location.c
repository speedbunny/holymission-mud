#define FILE "players/goldsun/obj/location"

string location, who;
int is_lost;

void reset(int arg){
 if (arg) return;
  restore_object(FILE);
}


void set_file(string s){
  location=s;
  save_object(FILE);
}

string query_location(){ return location; }

int query_is_lost(){  return is_lost; }

int set_is_lost(int i){ is_lost=i; }
 
void set_loose_who(string s){ who=s; }

string query_loose_who(){ return who; }

