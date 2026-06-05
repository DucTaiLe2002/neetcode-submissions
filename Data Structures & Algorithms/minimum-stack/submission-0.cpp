#include <stack>

class MinStack {
public:
    // Ngăn xếp chính để lưu trữ dữ liệu đầu vào
    std::stack<int> the_main_stack;
    
    // Ngăn xếp phụ để luôn theo dõi và lưu trữ giá trị nhỏ nhất hiện tại
    std::stack<int> the_minimum_stack;
    MinStack() {
        // Hàm khởi tạo không cần thực hiện gì thêm vì std::stack tự động khởi tạo rỗng
    }
    
    void push(int the_value) {
        the_main_stack.push(the_value);
        
        // Nếu ngăn xếp phụ rỗng, hoặc giá trị mới nhỏ hơn/bằng giá trị nhỏ nhất hiện tại,
        // ta đẩy nó vào ngăn xếp phụ.
        if (the_minimum_stack.empty() || the_value <= the_minimum_stack.top()) {
            the_minimum_stack.push(the_value);
        }
    }
    
    void pop() {
        // Nếu giá trị bị lấy ra khỏi ngăn xếp chính chính là giá trị nhỏ nhất,
        // ta cũng phải loại bỏ nó khỏi ngăn xếp phụ để cập nhật lại số nhỏ nhất.
        if (the_main_stack.top() == the_minimum_stack.top()) {
            the_minimum_stack.pop();
        }
        the_main_stack.pop();
    }
    
    int top() {
        return the_main_stack.top();
    }
    
    int getMin() {
        return the_minimum_stack.top();
    }
};