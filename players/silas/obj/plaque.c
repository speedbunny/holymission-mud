id(str) {
        return str == "plaque";
        }

short() {
return "bronze plaque";
        }

long() {
write("Feel free to emote here, just type <emote> <your feelings>.\n");
       }

reset(arg) {
  if (arg) return 1;
  return 1;
}

init() {
        add_action("read_plaque","read");
}

read_plaque(str) {
        if (!id(str)) return 0;
        long();
        return 1;
}
