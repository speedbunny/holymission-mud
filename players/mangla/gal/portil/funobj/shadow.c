#define FP find_player("portil")

set_shadow() {
        shadow(FP,1);
}

query_presentation() {
  string name;
  if(query_idle(find_player("portil"))>120) return "Portil seems to be idle. (Take a short while to respond)";
  
  return "Lord Fishy the third, kipper god of the realm";
}
