#define NUM "/guild/master"->query_number("druid")
#define CD "/sys/chatd"
#define TPN capitalize(this_player()->query_real_name())
//#define TPN this_player()->query_name()

status do_spell(string str) {
  if(!str) {
    this_player()->guild_line();
    return 1;
  }
  CD->do_chat(NUM, "[* Druid *] " + TPN + " " + str + "\n");
  return (1);
}
