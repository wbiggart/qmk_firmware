# wbiggart's DZ65RGBv2 ANSI Layout
Heavily copied from drootz
Will this take

## LEADER KEY BINDINGS

The leader key on this layout is triggered by tapping the "code" (key just below PgDn) key once. Once triggered, we have 450ms between each key press to type any one of the sequences listed below. All sequences are designed to work on both Mac and Windows with an English keyboard OS setting.

- [Special Characters and Ponctuation](#Special-Characters-and-Punctuation)
- [Text Selection Macros](#Text-Selection-Macros)
- [Expanded Space Cadet Macros](#Expanded-Space-Cadet-Macros)
- [Text Expanders](#Text-Expanders)

#### Legend:

| Acronym | Description |
| :--- | :--- |
| LDR | Leader Key |
| SFT | Shift key |
| CTL | Control key |
| ESC | Escape key |
| ¶ | Text cursor position |

### Special Characters and Punctuation

| Output | Sequence | Description |
| :--- | :--- | :--- |
| `±`¶ | `LDR  =  -` | n/a |
| `≤`¶ | `LDR  -  =` | n/a |
| `≥`¶ | `LDR  =  =` | n/a |
| `=>`¶ | `LDR  ,  ,` | n/a |
| `<=`¶ | `LDR  .  .` | n/a |
| ``` ` ``` ¶ | `LDR  ESC` | n/a |
| \`\`\` ¶ | `LDR  ESC  ESC  ESC` | n/a |
| `,` space ¶ | `LDR  SPACE` | n/a |
| `.` space ¶ | `LDR  SPACE  SPACE` | n/a |

### Text Selection Macros

| Output | Sequence |
| :--- | :--- |
| Select everything on this line before cursor | `LDR  LEFT-ARROW` |
| Select everything on this line after cursor | `LDR  RIGHT-ARROW` |
| Select everything on this line before cursor up to end of previous line | `LDR  LEFT-ARROW  LEFT-ARROW` | n/a |
| Select everything on this line | `LDR  RIGHT-ARROW  LEFT-ARROW` |
| Select 1x Page Up on the page before the cursor | `LDR  UP-ARROW` |
| Select 1x Page Down on the page after the cursor | `LDR  DOWN-ARROW` |
| Select everything on the page before the cursor | `LDR  UP-ARROW  UP-ARROW` |
| Select everything on the page after the cursor | `LDR  DOWN-ARROW  DOWN-ARROW` |

### Expanded Space Cadet Macros

| Output | Sequence | Description |
| :--- | :--- | :--- |
| `"`¶ | `LDR  '` | Will output single double-quote |
| `"`¶`"` | `LDR  '  '` | Will wrap cursor between two double-quotes |
| `"`WORD`"`¶ | `LDR  '  '  '` | Will wrap word on cursor between two double-quotes |
| `(`¶ | `LDR  LEFT-SFT` | Will output single left parenthesis |
| `)`¶ | `LDR  RIGHT-SFT` | Will output single right parenthesis |
| `(`¶`)` | `LDR  LEFT-SFT  LEFT-SFT` | Will wrap cursor between two parenthesis' |
| `(`¶`)` | `LDR  RIGHT-SFT  RIGHT-SFT` | Will wrap cursor between two parenthesis' |
| `(`WORD`)`¶ | `LDR  LEFT-SFT  W` | Will wrap word on cursor between two parenthesis' |
| `(`WORD`)`¶ | `LDR  RIGHT-SFT  W` | Will wrap word on cursor between two parenthesis' |
| `(`SELECTION`)`¶ | `LDR  LEFT-SFT  W  W` | Will wrap selection between two parenthesis' |
| `(`SELECTION`)`¶ | `LDR  RIGHT-SFT  W  W` | Will wrap selection between two parenthesis' |
| `[`¶ | `LDR  LEFT-CTL` | Will output single left bracket |
| `]`¶ | `LDR  RIGHT-CTL` | Will output single right bracket |
| `[`¶`]` | `LDR  LEFT-CTL  LEFT-CTL` | Will wrap cursor between two brackets' |
| `[`¶`]` | `LDR  RIGHT-CTL  RIGHT-CTL` | Will wrap cursor between two brackets' |
| `[`WORD`]`¶ | `LDR  LEFT-CTL  W` | Will wrap word on cursor between two brackets' |
| `[`WORD`]`¶ | `LDR  RIGHT-CTL  W` | Will wrap word on cursor between two brackets' |
| `[`SELECTION`]`¶ | `LDR  LEFT-CTL  W  W` | Will wrap selection between two brackets' |
| `[`SELECTION`]`¶ | `LDR  RIGHT-CTL  W  W` | Will wrap selection between two brackets' |
| `{`¶ | `LDR  LEFT-ALT` | Will output single left curly brace |
| `}`¶ | `LDR  RIGHT-ALT` | Will output single right curly brace |
| `{`¶`}` | `LDR  LEFT-ALT  LEFT-ALT` | Will wrap cursor between two curly braces' |
| `{`¶`}` | `LDR  RIGHT-ALT  RIGHT-ALT` | Will wrap cursor between two curly braces' |
| `{`WORD`}`¶ | `LDR  LEFT-ALT  W` | Will wrap word on cursor between two curly braces' |
| `{`WORD`}`¶ | `LDR  RIGHT-ALT  W` | Will wrap word on cursor between two curly braces' |
| `{`SELECTION`}`¶ | `LDR  LEFT-ALT  W  W` | Will wrap selection between two curly braces' |
| `{`SELECTION`}`¶ | `LDR  RIGHT-ALT  W  W` | Will wrap selection between two curly braces' |

