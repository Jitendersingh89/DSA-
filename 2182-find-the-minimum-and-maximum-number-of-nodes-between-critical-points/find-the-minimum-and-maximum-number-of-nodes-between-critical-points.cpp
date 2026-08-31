class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || 
            head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;
        int first = -1;
        int prevCritical = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next != nullptr) {
            int nextVal = curr->next->val;

            bool critical =
                (curr->val > prev->val && curr->val > nextVal) ||
                (curr->val < prev->val && curr->val < nextVal);

            if (critical) {
                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - prevCritical);
                }

                prevCritical = pos;
                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (first == -1 || first == last)
            return ans;

        return {minDist, last - first};
    }
};