id(str) {
        return str == "notice";
        }

short() {
return "A VERY IMPORTANT NOTICE";
        }

long() {
write("   The bugs with the houses are all fixed now, but if you should\n");
write("stumble across something let me know. All the features listed in the\n");
write("help mode work now, and a new 'furnish' command has been added. If\n");
write("you are thinking about a new house, ask a current owner if he will\n");
write("show you around first so that you know what you will be buying. Also\n");
write("if you should lose your key, come back to this office and examine \n");
write("the real estate agent. A new key will be given to you promptly.\n");
write("-Silas\n");
       }

reset(arg) {
  if (arg) return 1;
  return 1;
}

init() {
        add_action("read_sign","read");
}

read_sign(str) {
        if (!id(str)) return 0;
        long();
        return 1;
}
