const fs = require("fs");
const { Solution } = require("./Solution");
const { printFailedCase } = require("../../../Javascript/helper");

let testcases = [];
//  testcases: array of objects
//  {
//      arg1: String,
//      output: String
// }
main();

function main() {
  let Success = true;
  getTestCases();
  const sizeOfTestCases = testcases.length;

  for (let i = 0; i < sizeOfTestCases; i++) {
    let arg1 = testcases[i].arg1;
    const user_code_output = Solution(arg1);

    if (user_code_output !== testcases[i].output) {
      printFailedCase({
        arg1: arg1,
        arg2: null,
        arg3: null,
        arg4: null,
        actual_output: user_code_output,
        expected_output: testcases[i].output,
      });

      Success = false;
      break;
    }
  }

  if (Success) {
    console.log("Result: Success");
  }
}

function getTestCases() {
  try {
    let data = fs.readFileSync(
      "proddata/data/make_the_string_great/testcases.txt",
      "utf8"
    );
    data = data.split("\n");

    for (let i = 1; i < data.length; i++) {
      let input1 = data[i].trim();
      input1 = input1.slice(1, input1.length - 1);

      // jumps to output of that testcase
      i++;

      let output = data[i].trim();
      output = output.slice(1, output.length - 1);

      testcases.push({
        arg1: input1,
        output: output,
      });
    }
  } catch (err) {
    console.error(err);
  }
}
