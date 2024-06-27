#include <iostream>
#include <instinct/llm_all.hpp>

int main()
{
    using namespace INSTINCT_CORE_NS;
    using namespace INSTINCT_LLM_NS;

    const auto input_parser = CreatePromptVariantInputParser();
    const auto string_prompt = CreatePlainPromptTemplate("Answer following question in one sentence: {question}");
    const auto output_parser = CreateStringOutputParser();
    const auto chat_model = CreateOllamaChatModel();
    const auto xn = input_parser | string_prompt |  chat_model->AsModelFunction() | output_parser;

    { // run in sync way
        const auto result = xn->Invoke("Why sky is blue?");
        std::cout << result <<std::endl;
    }

    { // run in async way
        xn->Stream("Tell me something interesting about China.")
            | rpp::ops::as_blocking()
            | rpp::ops::subscribe([](const auto x) {
                std::cout << x;
            }, [] {
                std::cout << std::endl;
            });
    }
}
