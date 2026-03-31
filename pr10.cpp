#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5,6 };

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	for (int x : v) {
		cout << x << endl;
	}
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5,6 };

	auto it = find(v.begin(), v.end(), 3);

	if (it != v.end())
		cout << "Found\n";
	else
		cout << "Not found\n";
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5,6 };

	auto min_it = min_element(v.begin(), v.end());
	auto max_it = max_element(v.begin(), v.end());

	if (min_it != v.end())
		cout << "Min: " << *min_it << endl;
	if (max_it != v.end())
		cout << "Max: " << *max_it << endl;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,3,5,6 };
	int a = 3;

	int s = count(v.begin(), v.end(), a);
	cout << "Number: " << a << " meets " << s << " times" << endl;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,3,5,6 };

	reverse(v.begin(), v.end());
	
	cout << "It is reversed\n";
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,3,2,4,7,5,6 };

	sort(v.begin(), v.end());
	
	sort(v.begin(), v.end(), [](int a, int b) {
		return a > b;
	});
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,3,2,4,7,5,6 };
	int X = 4;

	v.erase(remove_if(v.begin(), v.end(), [X](int x) {
		return x == X;
	}), v.end());
	
	for (int x : v)
		cout << x << " ";
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,3,20,4,70,5,6 };

	v.erase(remove_if(v.begin(), v.end(), [](int x) {
		return x > 10;
	}), v.end());
	
	for (int x : v)
		cout << x << " ";
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,3,20,4,70,5,6 };

	sort(v.begin(), v.end());

	auto it = unique(v.begin(), v.end());

	v.erase(it, v.end());
	
	for (int x : v)
		cout << x << " ";
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,3,20,4,70,5,6 };
	vector<int> result(v.size());

	transform(v.begin(), v.end(), result.begin(), [](int x) { return x * 2; });

	for (int x : v)
		cout << x << " ";
}


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	vector<int> v = { 1,3,20,4,70,5,6 };
	
	unordered_map<int, int> freq;

	for (int x : v)
		freq[x]++;

	for (auto const& x : freq) {
		cout << x.first << ": " << x.second << endl;
	}
}


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	vector<int> v = { 1,3,20,4,70,5,70 };
	
	unordered_map<int, int> freq;

	for (int x : v)
		freq[x]++;

    int maxCount = 0;
    int mostFrequentNumber = v[0];

    for (const auto& pair : freq) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentNumber = pair.first;
        }
    }

    cout << mostFrequentNumber << endl;
}


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> ages = { {"Alice", 30}, {"Bob", 25} };
    string key = "Alice";

    if (ages.count(key)) {
        cout << "Key found(count)" << endl;
    }

    auto it = ages.find(key);
    if (it != ages.end()) {
        cout << "Found: " << it->second << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    return 0;
}


#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main() {
    string text = "hello world hello";

    set<string> unique_words;
    stringstream s(text);
    string word;

    while (s >> word) {
        unique_words.insert(word);
    }

    for (const auto& w : unique_words) {
        cout << w << endl;
    }
}


#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string text = "hello world hello";

    map<string, int> wordCount;
    stringstream s(text);
    string word;

    while (s >> word) {
        wordCount[word]++;
    }

    for (const auto& w : wordCount) {
        cout << w.first << ": " << w.second << endl;
    }
}


#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
        else {
            std::cout << "Стек пуст!\n";
        }
    }

    void top() const {
        if (!data.empty()) {
            std::cout << "Верхний элемент: " << data.back() << "\n";
        }
        else {
            std::cout << "Стек пуст!\n";
        }
    }

    bool empty() const {
        return data.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.top();

    s.pop();
    s.top();

    s.pop();
    s.top();

    return 0;
}


#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> taskQueue;

    taskQueue.push("Task 1: Email");
    taskQueue.push("Task 2: Data Processing");
    taskQueue.push("Task 3: Report Gen");

    std::cout << "Tasks in queue: " << taskQueue.size() << "\n\n";

    while (!taskQueue.empty()) {
        std::string currentTask = taskQueue.front();
        std::cout << "Processing: " << currentTask << std::endl;

        taskQueue.pop();
    }

    std::cout << "\nAll tasks processed. Queue size: " << taskQueue.size() << std::endl;

    return 0;
}


#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    std::cout << "New:" << std::endl;

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {5,1,9,3,7};

    sort(v.begin(), v.end(), greater<int>());

    for(int i = 0; i < 3; i++)
        cout << v[i] << " ";
}


#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = { 5, -3, 8, -1, 0, 10, -7, 2 };

    numbers.erase(std::remove_if(numbers.begin(), numbers.end(),
        [](int x) { return x < 0; }), numbers.end());

    std::sort(numbers.begin(), numbers.end());

    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}
