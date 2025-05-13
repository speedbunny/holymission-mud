inherit "obj/thing";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("calculator");
  set_alias("calc");
  set_short("Uglymouth's calculator");
  set_long("A very primitive calculator.\n"
    + "Syntax: calc <fig1> <proc> <fig2>.\n");
  }

void init() {
  ::init();
  add_action("calc_it","calc");
  }

int calc_it(string str) {
int fig1,fig2;
mixed res;
string proc;
  if(!str) return 0;
  if(sscanf(str,"%d %s %d",fig1,proc,fig2)!=3) return 0;
  switch(proc) {
    case "+": res = fig1 + fig2;  break;
    case "-": res = fig1 - fig2;  break;
    case "*": res = fig1 * fig2;  break;
    case "/": if(fig2!=0) res = fig1 / fig2;
              else res = "division by zero";
              break;
    default : res = "incomprehensible"; break;
    }
  write("The result of "+str+" is "+res+".\n");
  return 1;
  }
