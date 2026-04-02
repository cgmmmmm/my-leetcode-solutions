class TextEditor {
private:
    std::stack<char> left;
    std::stack<char> right;

public:
    TextEditor() {
    }
    
    void addText(string text) {
        for (char ch : text) {
            left.push(ch);
        }
    }
    
    int deleteText(int k) {
        int deleteCnt = k;
        while (!left.empty() && deleteCnt>0) {
            left.pop();
            deleteCnt--;
        }
        return k - deleteCnt;
    }
    
    string cursorLeft(int k) {
        while (!left.empty() && k>0) {
            right.push(left.top());
            left.pop();
            k--;
        }
        
        std::vector<char> v;
        int retSize = std::min(10, static_cast<int>(left.size()));
        while (!left.empty() && retSize>0) {
            v.push_back(left.top());
            left.pop();
            retSize--;
        }

        std::string res;
        for (int i=v.size()-1; i>=0; i--) {
            res += v[i];
            left.push(v[i]);
        }

        return res;
    }
    
    string cursorRight(int k) {
        while (!right.empty() && k>0) {
            left.push(right.top());
            right.pop();
            k--;
        }

        std::vector<char> v;
        int retSize = std::min(10, static_cast<int>(left.size()));
        while (!left.empty() && retSize>0) {
            v.push_back(left.top());
            left.pop();
            retSize--;
        }

        std::string res;
        for (int i=v.size()-1; i>=0; i--) {
            res += v[i];
            left.push(v[i]);
        }

        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
