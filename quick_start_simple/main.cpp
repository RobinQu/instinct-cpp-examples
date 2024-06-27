#include <iostream>
#include <instinct/chain/message_chain.hpp>
#include <instinct/input_parser/prompt_value_variant_input_parser.hpp>
#include <instinct/chat_model/ollama_chat.hpp>
#include <instinct/output_parser/string_output_parser.hpp>
#include <instinct/prompt/plain_prompt_template.hpp>

int main()
{
    using namespace INSTINCT_CORE_NS;
    using namespace INSTINCT_LLM_NS;

    const auto input_parser = CreatePromptVariantInputParser();
    const auto string_prompt = CreatePlainPromptTemplate("Answer following question in one sentence: {question}");
    const auto output_parser = CreateStringOutputParser();
    const auto chat_model = CreateOllamaChatModel();
    const auto xn = input_parser | string_prompt |  chat_model->AsModelFunction() | output_parser;
    const auto result = xn->Invoke("Why sky is blue?");
    std::cout << result <<std::endl;
}
