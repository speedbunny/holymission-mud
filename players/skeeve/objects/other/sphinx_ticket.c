id(str) { return str=="sphinx_ticket"; }

status solved;
string which,text;

extra_look() { return (capitalize(environment()->query_pronoun()) + " had " + 
            ((solved ) ? "solved the":"got a") +" riddle from the sphinx"); }

set_solved(s) {solved=s;}
query_solved(){ return solved;}

set_riddle(w) {which = w;}
query_riddle(){return which;}

set_text(t) {text = t;}
query_text() {return text;}

drop() { return 1; }    /* dont drop it */

reset(arg) {
  if (!arg) {
    solved =0;
    which=0;
    text=0;
  }
}

init(){
  add_action("riddle","riddle");
}

riddle() {
  write (text);
  return 1;
}
