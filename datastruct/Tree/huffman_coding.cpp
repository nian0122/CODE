#include <iostream>
#include <string>
#include <queue>
#include <vector>
typedef struct HuffmanNode{
    char data;
    int frequency;
    struct HuffmanNode *left, *right;
}HuffmanNode;

typedef struct Compare{
    bool operator()(
        const HuffmanNode* a,const HuffmanNode *b
    ){
        return a->frequency > b->frequency;
    }
};

HuffmanNode* createNode(char data, int frequency, HuffmanNode* left, HuffmanNode* right){
    HuffmanNode* node = new HuffmanNode();
    node->data = data;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

void generateCodes(const HuffmanNode* root, std::string current_code, std::string codes[]){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        codes[(unsigned char)root->data] = current_code;
    }
    generateCodes(root->left,current_code + "0", codes);
    generateCodes(root->right,current_code + "1", codes);
}

HuffmanNode* buildHuffmanTree(const std::string& text){

    int freqMap[256]={0};
    for(char c : text){
        freqMap[(unsigned char)c]++;
    }

    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;

    for (int i = 0; i < 256; ++i) {
        if(freqMap[i] > 0){
            pq.push(createNode((char)i,freqMap[i], nullptr,nullptr));
        }
    }

    while(pq.size() > 1){
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = createNode('\0',left->frequency + right->frequency,left,right);
        pq.push(newNode);
    }
    return pq.top();
}

std::string encode(const std::string& text, const std::string codes[]){
    std::string encoded_string="";
    for(char c : text){
        encoded_string += codes[(unsigned char)c];
    }
    return encoded_string;
}

std::string decode(const HuffmanNode* root, const std::string& encoded_string){
    std::string decoded_string = "";
    const HuffmanNode* current_node = root;
    for(char bit : encoded_string){
        if (bit == '0'){
            current_node = current_node->left;
        }else{
            current_node = current_node->right;
        }
        if(!current_node->left && !current_node->right){
            decoded_string += current_node->data;
            current_node = root;
        }
    }
    return decoded_string;
}

void freeTree(HuffmanNode* root){
    if(!root){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
// --- 測試部分 ---
int main() {
    std::string original_text = "this is an example for huffman encoding";

    if (original_text.empty()) {
        std::cout << "输入文本为空！" << std::endl;
        return 0;
    }

    std::cout << "--- 哈夫曼编码测试 ---" << std::endl;
    std::cout << "原始文本: " << original_text << std::endl;
    std::cout << "--------------------------------\n" << std::endl;

    // 1. 建構哈夫曼樹
    HuffmanNode* root = buildHuffmanTree(original_text);

    // 2. 生成哈夫曼編碼
    std::string huffmanCodes[256];
    generateCodes(root, "", huffmanCodes);

    std::cout << "生成的哈夫曼编码:" << std::endl;
    for (int i = 0; i < 256; ++i) {
        if (!huffmanCodes[i].empty()) {
            std::cout << "'" << (char)i << "' : " << huffmanCodes[i] << std::endl;
        }
    }
    std::cout << "--------------------------------\n" << std::endl;

    // 3. 編碼原始文本
    std::string encoded_text = encode(original_text, huffmanCodes);
    std::cout << "编码后的文本 (二進位字串):" << std::endl;
    std::cout << encoded_text << std::endl;
    std::cout << "--------------------------------\n" << std::endl;

    // 4. 解碼文本
    std::string decoded_text = decode(root, encoded_text);
    std::cout << "解码后的文本: " << decoded_text << std::endl;
    std::cout << "--------------------------------\n" << std::endl;

    // 5. 驗證結果
    std::cout << "检验:" << std::endl;
    if (original_text == decoded_text) {
        std::cout << "✅ 成功！解码后的文本与原始文本完全一致。" << std::endl;
    } else {
        std::cout << "❌ 失敗！解码后的文本与原始文本不匹配。" << std::endl;
    }

    // 6. 清理記憶體
    freeTree(root);
    std::cout << "\n哈夫曼记忆树以释放。" << std::endl;

    return 0;
}
