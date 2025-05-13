#ifndef __P_PROMPT_C__

#define __P_PROMPT_C__

#include "player_defs.h"
#include "player_prompt.h"

int c_prompt(string str) {
  string tmp;
  int show_path, show_day, show_time, show_num;

  if(!prompt || sizeof(prompt)!=sizeof(DEF_PROMPT))
    prompt = DEF_PROMPT;
  if(!str) {
    show_path = ((TO->IMM || TO->TESTC) ? 1 : 0 && prompt[PR_CWD]);
    show_day = ((TO->IMM || TO->TESTC) ? 1 : 0 && prompt[PR_DAY]);
    show_time = ((TO->IMM || TO->TESTC) ? 1 : 0 && prompt[PR_TIM]);
    show_num = ((TO->IMM || TO->TESTC) ? 1 : 0 && prompt[PR_NUM]);
    tmp = (show_num ? "# - " : "") +
          (show_day ? "<day> - " : "") +
          (show_time ? "<time> - " : "") +
          (show_path ? "<current_path> - " : "")[0..<3];
    write("Your current prompt is:\n");
    write((prompt[PR_CR1] ? "\n" : ""));
    write("HP:" + (prompt[PR_HP] ? "on " : "off "));
    write("SP:" + (prompt[PR_SP] ? "on " : "off "));
    write("<monster>:" + (prompt[PR_MON] ? "on " : "off "));
    write("<victim>:" + (prompt[PR_VIC] ? "on " : "off "));
    write((prompt[PR_CR2] ? "\n" + tmp + ">>\n" : ">\n"));
    if(prompt[PR_FIG])
      write("The stats are always shown in a fight.\n");
    write("and you " + (prompt[PR_ALL] ? "" : "don't ") +
          "get the stats all the time.\n");
    return 1;
  }
  switch(str) {
    case "hp":
      prompt[PR_HP] = !prompt[PR_HP];
      write("HP turned " + (prompt[PR_HP] ? "on.\n" : "off.\n"));
      break;
    case "sp":
      prompt[PR_SP] = !prompt[PR_SP];
      write("SP turned " + (prompt[PR_SP] ? "on.\n" : "off.\n"));
      break;
    case "mon":
      prompt[PR_MON] = !prompt[PR_MON];
      write("<monster> turned " + (prompt[PR_MON] ? "on.\n" : "off.\n"));
      break;
    case "cr1":
      prompt[PR_CR1] = !prompt[PR_CR1];
      write("Leading LF turned " + (prompt[PR_CR1] ? "on.\n" : "off.\n"));
      break;
    case "cr2":
      prompt[PR_CR2] = !prompt[PR_CR2];
      write("Trailing LF turned " + (prompt[PR_CR2] ? "on.\n" : "off.\n"));
      break;
    case "vic":
      prompt[PR_VIC] = !prompt[PR_VIC];
      write("Victim's HP turned " + (prompt[PR_VIC] ? "on.\n" : "off.\n"));
      break;
    case "perm":
      prompt[PR_ALL] = !prompt[PR_ALL];
      write("Permanent Stats turned " + (prompt[PR_ALL] ? "on.\n" : "off.\n"));
      break;
    case "fight":
      prompt[PR_FIG] = !prompt[PR_FIG];
      write("Stats only in fights turned " +
            (prompt[PR_FIG] ? "on.\n" : "off.\n"));
      break;
    case "cwd":
      if(TO->IMM || TO->TESTC) {
        prompt[PR_CWD] = !prompt[PR_CWD];
        write("Cwd turned " + (prompt[PR_CWD] ? "on.\n" : "off.\n"));
      }
      else {
        notify_fail("Type 'help prompt' for more help on prompts.\n");
        return 0;
      }
      break;
    case "day":
      if(TO->IMM || TO->TESTC) {
        prompt[PR_DAY] = !prompt[PR_DAY];
        write("Day turned " + (prompt[PR_DAY] ? "on.\n" : "off.\n"));
      }
      else {
        notify_fail("Type 'help prompt' for more help on prompts.\n");
        return 0;
      }
      break;
    case "time":
      if(TO->IMM || TO->TESTC) {
        prompt[PR_TIM] = !prompt[PR_TIM];
        write("Time turned " + (prompt[PR_TIM] ? "on.\n" : "off.\n"));
      }
      else {
        notify_fail("Type 'help prompt' for more help on prompts.\n");
        return 0;
      }
      break;
    case "number":
      if(TO->IMM || TO->TESTC) {
        prompt[PR_NUM] = !prompt[PR_NUM];
        write("Command number turned " +
              (prompt[PR_NUM] ? "on.\n" : "off.\n"));
      }
      else {
        notify_fail("Type 'help prompt' for more help on prompts.\n");
        return 0;
      }
      break;
    case "all":
      show_path = (TO->IMM || TO->TESTC) ? 1 : 0;
      show_day = (TO->IMM || TO->TESTC) ? 1 : 0;
      show_time = (TO->IMM || TO->TESTC) ? 1 : 0;
      show_num = (TO->IMM || TO->TESTC) ? 1 : 0;
      prompt = ({ 1,1,1,1,1,1,1,1,show_path,show_day,show_time,show_num });
      write("All prompt options set.\n");
      break;
    case "none":
      prompt = ({ 0,0,0,0,0,0,0,0,0,0,0,0 });
      write("All prompt options reset.\n");
      break;
    case "default":
      prompt = DEF_PROMPT;
      write("Prompt reset to default.\n");
      break;
    default:
      notify_fail("Type 'help prompt' for more help on prompts.\n");
      return 0;
  }
  return 1;
}

int *conf_prompt() {
  if(sizeof(prompt) != sizeof(DEF_PROMPT))
    prompt = DEF_PROMPT;
  return prompt;
}

varargs mixed query_prompt(int flag, int num) {
  if(sizeof(prompt) != sizeof(DEF_PROMPT))
    prompt = DEF_PROMPT;
  if(flag) {
    if(num>=0 && num<sizeof(DEF_PROMPT))
      return prompt[num];
    else return 0;
  }
  else
    return prompt;
}

#endif // __P_PROMPT_C__
