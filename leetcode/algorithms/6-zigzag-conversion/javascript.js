/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function (s, numRows) {
  // can not zigzeg
  if (numRows === 1 || s.length < numRows) {
    return s;
  }

  // can zigzeg
  let sArray = new Array();

  for (let i = 0; i < numRows; i++) {
    sArray[i] = new Array();
  }

  let j = 0;
  let zigzegDirectionChanged = false;
  let y = parseInt(s.length / numRows + 2);
};
