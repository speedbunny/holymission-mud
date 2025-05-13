// ----------------------------------------------------------------------- //
//   GENERIC BOARD                                                         //
// ----------------------------------------------------------------------- //

// 201096: Sauron: Added new post info funs.
// 130397: Sauron: General maintainence.
// 300997: Sauron: Added catchup command - reads all unread notes on a
//                 board.

#include <lw.h>

#define TP		this_player()
#define MAX_HEADLINE	45
#define MIN_LEVEL	0

static string name,board_file,idx_file,my_env,input_text,input_hl;
static int input_line;
static object input_who;

mixed *idx;             // {headline} {who} {date} {index}
int last_post;          // When was the last note posted?
mapping last_read;      // Info on the last note everyone read.

// Prototypes:

int id(string wwi);
int query_last_post();
int query_num_notes();
void reset_last_read();
varargs mixed query_last_read(int flag);
varargs int query_new_posts(string str);
int do_note(string str);
int do_re(string str);
static void enter_text(string txt);
static void input_aborted();
static void input_finished();
int do_dump(string str);
string read_note(int no, int size);
int do_read(string str);
int do_catchup();
int valid_remove(object who, int no);
void reduce_last_read(int no);
int do_remove(string str);
void set_name(string n);
string query_name();
string query_real_name();
string query_environment();
string short();
void long();
void reset(int arg);
void init();

// f = file; s = start-byte; e = end-byte+1 !! (end-byte won't be read !)

private string my_read_bytes(string f, int s, int e) {
  return read_bytes(f, s, (e-s));
}

int id(string wwi) {
  return wwi == name || wwi == "board";
}

int query_last_post() {
  return last_post;
}

int query_num_notes() {
  return sizeof(idx[0]);
}

void reset_last_read() {
  if(!TP || !TP->query_archwiz())
    return;
  else {
    last_read = ([]);
    write("Ok.\n");
  }
}

varargs mixed query_last_read(int flag) {
  if(!last_read)
    last_read = ([]);
  if(!TP)
    return 0;
  else if(flag)
    return last_read[TP->query_real_name()];
  else {
    if(!TP->query_archwiz())
      return ([]);
    else
      return last_read;
  }
}

varargs int query_new_posts(string str) {
  int    ret;
  object tp;

  tp = TP;

  if(!str || str == "") {
    if(tp)
      str = (string)tp->query_real_name();
    else
      return 0;
  }
  else {
    if(!tp || !(int)tp->query_archwiz())
      return 0;
  }

  if(!last_read)
    last_read = ([]);

  ret = query_num_notes()-last_read[str];
  if(ret < 0)
    ret = 0;
  return ret;
}

int do_note(string str) {
  if(TP->query_level()<MIN_LEVEL) {     // level-limitation
    notify_fail("Sorry, but you are too low-level to post a \
note.\n");
    return 0;
  }
  if(TP->query_real_name() == "guest") {
    notify_fail("Come up with a real character or shut up.\n");
    return 0;
  }
  else if(!str) {                       // you must give a headline
    notify_fail("Please give a headline.\n" );
    return 0;
  }
  else if(strlen(str)>MAX_HEADLINE) {   // headline too long
    notify_fail("Headline too long, please shorten it.\n");
    return 0;
  }
  else if(!interactive(TP)) {           // not an interactive
    notify_fail("You ain't nothing but a hound-dog!\n");
    return 0;
  }
// s.b. already noting
  else if(input_line > 0 && input_who && interactive(input_who)) {
    writelw(sprintf("%s is writing a note, please be patient.\n",
                    input_who->query_real_name(1)));
    return 1;
  }

  input_text = "";
  input_line = 1;
  input_who = TP;
  input_hl = str;

  write("Please enter your message. Finish with '**' or '@', abort with \
'~q'\n");
  printf("%2d>> ", input_line);
  input_to("enter_text",0);

  return 1;
}

int do_re(string str) {
  string hl;
  int    no;

  if(!str || str == "")
    no = sizeof(idx[0]);
  else
    no = to_int(str);

  if(no < 0 || no > sizeof(idx[0])) {
    notify_fail("This note only exists in your imagination.\n");
    return 0;
  }

  hl = idx[0][no-1];
  if(hl[0..3] != "Re: ")
    hl = "Re: "+hl;

  if(strlen(hl) > MAX_HEADLINE)
    hl = hl[0..MAX_HEADLINE-1];

  return do_note(hl);
}

static void enter_text(string txt) {
  if(txt == "**" || txt == "@")
    input_finished();
  else if(txt == "~q")
    input_aborted();
  else {
    input_text += (txt+"\n");
    input_line++;
    printf("%2d>> ", input_line);
    input_to("enter_text",0);
  }
}

static void input_aborted() {
  write("A small gnome arrives and tears the note to pieces...\n");
  input_line = 0;
  input_who = 0;
  input_text = 0;
  input_hl = 0;
}

static void input_finished() {
  string name;
  int    size;

  if(input_line > 1) {
    write("A small gnome arrives and fixes the message to the \
board...\n");
    if(!last_read)
      last_read = ([]);
    name = (string)input_who->query_real_name();
    if(query_num_notes() == last_read[name])
      last_read[name] = query_num_notes()+1;

    idx[0] += ({input_hl});
    idx[1] += ({input_who->query_real_name()});
    idx[2] += ({ctime()[4..9]});
    size = sizeof(idx[3]);
    input_text = sprintf("[%-15s] [%6s] [%-45s]\n",
                         idx[1][size], idx[2][size],
                         idx[0][size])+"\n"+input_text;
    if(!size)
      idx[3] += ({0});
    else
      idx[3] += ({file_size(board_file)});
    last_post = time();
    write_file(board_file, input_text);
    save_object(idx_file);
  }
  else
    writelw("A small gnome arrives, looks at the empty sheet, puts it \
into his pocket, and leaves.\n");

   input_line = 0;
   input_who = 0;
   input_text = 0;
   input_hl = 0;
}

int do_dump(string str) {
  string res;
  int    no_notes, i;

  if(!TP || !TP->query_archwiz() || !interactive(TP) || !id(str))
    return 0;

  res = "DUMP OF BOARD "+name+"\nLast post time: "+ctime(last_post)+"\n\n";
  no_notes = sizeof(idx[0]);
  if(!no_notes)
    res += "The board is empty.\n";
  else {
    for(i = 0; i < no_notes; i++)
      res+=sprintf("%-15s %-6s %-45s %4d\n",
                   idx[1][i], idx[2][i], idx[0][i], idx[3][i]);
  }

  TP->more_string(res);
  return 1;
}

string read_note(int no, int size) {
  string ret, name;
  int    start, end;

  start = idx[3][no-1];
  if(no == size)
    end = file_size(board_file);
  else
    end = idx[3][no];
  ret = my_read_bytes(board_file, start, end);
  ret += "\nEnd of note "+no+".\n";

  if(!last_read)
    last_read = ([]);
  name = (string)TP->query_real_name();
  if(no > last_read[name])
    last_read[name] = no;

  save_object(idx_file);
  return ret;
}

int do_read(string str) {
  int no,size;

  if(!str || str == "") {
    no = query_last_read(1)+1;
    if(no > size)
      no = 0;
  }
  else
    no = to_int(str);
  size = sizeof(idx[0]);
  if(no < 1) {
    notify_fail("Read....Read...Read? READ!!!!! But which note?\n");
    return 0;
  }
  else if(no > size) {
    notify_fail("This note only exists in your imagination.\n");
    return 0;
  }
  else {
    TP->more_string(read_note(no, size));
    return 1;
  }
}

int do_catchup() {
  string ret;
  int    i, no, size;

  no = query_last_read(1);
  size = sizeof(idx[0]);

  if(no < size) {
    ret = "";
    for(i = no+1; i <= size; i++)
      ret += (read_note(i,size)+"\n");
  }
  else
    ret = "No new notes.\n";

  TP->more_string(ret);
  return 1;
}

int valid_remove(object who, int no) {
  string *tok;

  if(!who || !no || no>sizeof(idx[0]))
    return 0;
  if(!interactive(who))
    return 0;
  if(who->query_archwiz())
    return 1;
  if(who->query_real_name() == idx[1][no-1])
    return 1;
  tok = explode(file_name(environment(this_object())), "/");
  if(tok[1] == who->query_real_name())
    return 1;
  else
    return 0;
}

void reduce_last_read(int no) {
  string *ind;
  int    i;

  ind = m_indices(last_read);
  for(i = 0; i < sizeof(ind); i++)
    if(last_read[ind[i]] >= no)
      last_read[ind[i]]--;
}

int do_remove(string str) {
  string tmp, *ind;
  int    no, size, fsize, len, i, j;

  no = to_int(str);
  size = sizeof(idx[0]);
  if(no < 1) {
    write("Yeah, do it! But which one?\n");
    return 1;
  }
  else if(no > size) {
    write("This note only exists in your imagination.\n");
    return 1;
  }

  if(!valid_remove(TP, no)) {
    writelw("You try to remove the note, but a small gnome appears and \
hits your fingers!\n");
    return 1;
  }

  reduce_last_read(no);

  fsize = file_size(board_file);
  if(size == 1) {
    rm(board_file);
    idx = ({({}), ({}), ({}), ({})});
    write("A small gnome arrives, takes the last note and eats it!\n");
    save_object(idx_file);
    return 1;
  }

  if(no == 1)
    tmp = my_read_bytes(board_file, idx[3][1], fsize);
  else if(no == size)
    tmp = my_read_bytes(board_file, 0, idx[3][size-1]);
  else {
    tmp = my_read_bytes(board_file, 0, idx[3][no-1]);
    tmp += my_read_bytes(board_file, idx[3][no], fsize);
  }

  write_file(board_file+".tmp", tmp);
  rm(board_file);
  rename(board_file+".tmp", board_file);

  if(no < size) {
    len = idx[3][no]-idx[3][no-1];
    i = size-1;
    while(i >= no) {
      idx[3][i] -= len;
      i--;
    }
  }
  idx[0] = idx[0][0..no-2]+idx[0][no..<1];
  idx[1] = idx[1][0..no-2]+idx[1][no..<1];
  idx[2] = idx[2][0..no-2]+idx[2][no..<1];
  idx[3] = idx[3][0..no-2]+idx[3][no..<1];

  save_object(idx_file);

  write("A small gnome arrives, takes the note and eats it!\n");
  return 1;
}

void set_name(string n) {
  name = n;
}

string query_name() {
  int sz, un;

  sz = sizeof(idx[0]);
  un = query_new_posts();
  return sprintf("%s [%d note%s%s]",
                 (name ? name : "No Name"),
                 sz,
                 (sz == 1 ? "" : "s"),
                 (un ? ", "+un+" unread" : ""));
}

string query_real_name() {
  return name;
}

string query_environment() {
  return my_env;
}

string short() {
  return query_name();
}

void long() {
  string res;
  int    no_notes, i;

  res = query_name()+"\n\
Usage: write <headline>, read <number>, catchup, re <number>,\n\
       remove <number>\n\n";

  no_notes = sizeof(idx[0]);
  if(!no_notes)
    res += "The board is empty.\n";
  else {
    for(i = 0; i < no_notes; i++)
      res += sprintf("[%2d] %-15s %-6s %-45s\n",
                     i+1, idx[1][i], idx[2][i], idx[0][i]);
  }

  TP->more_string(res);
}

void reset(int arg) {
  string *expl, fn;

  if(arg)
     return;

  expl = explode(explode(file_name(this_object()), "#")[0], "/");
  fn = expl[<1];
  expl -= ({fn});
  board_file = "/"+implode(expl, "/")+"/data/"+fn+".brd";
  idx_file = "/"+implode(expl, "/")+"/idx/"+fn;
  my_env = 0;
  restore_object(idx_file);
  if(!idx)
    idx = ({({}),({}),({}),({})});
  if(!last_post)
    last_post = time();

  input_line = 0;
  input_text = 0;
  input_who = 0;
  input_hl = 0;
}

void init() {
  if(my_env && my_env != file_name(environment()))
     destruct(this_object());
  if(environment(TP) == this_object())
     destruct(this_object());

  add_action("do_note",   "note");
  add_action("do_note",   "write");
  add_action("do_re",     "re");
  add_action("do_read",   "read");
  add_action("do_read",   "r");
  add_action("do_remove", "remove");
  add_action("do_remove", "rem");
  add_action("do_dump",   "dump");
  add_action("do_catchup","catchup");
  add_action("do_catchup","ca");
}
