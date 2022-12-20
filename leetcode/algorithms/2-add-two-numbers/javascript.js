/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  let sum = 0;
  let temp = 0;
  const result = new ListNode(0);
  let headList = result;
  while (l1 !== null || l2 !== null || temp !== 0) {
    sum = 0;

    if (temp === 1) {
      sum += 1;
    } else if (temp === 2) {
      sum += 2;
    }

    temp = 0;

    if (l1 !== null) {
      sum += l1.val;
      l1 = l1.next;
    }
    if (l2 !== null) {
      sum += l2.val;
      l2 = l2.next;
    }

    if (sum >= 20) {
      sum -= 20;
      temp = 2;
    } else if (sum >= 10) {
      sum -= 10;
      temp = 1;
    }

    headList.next = new ListNode(sum);
    headList = headList.next;
  }

  return result.next;
};
