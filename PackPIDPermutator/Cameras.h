#pragma once

#include <map>

static const std::map<std::wstring, std::wstring> cameras {
    // Gobi Family
    {L"F027", L"Gobi/XTM-640 - GigEVision"},
    {L"F028", L"Gobi/XTM-640 - Analog"},
    {L"F029", L"Gobi/XTM-640 - Camera Link"},

    {L"F02C", L"Gobi/XTM-384 - GigEVision"},
    {L"F02D", L"Gobi/XTM-384 - Analog"},
    {L"F02E", L"Gobi/XTM-384 - Camera Link"},

    // Serval Family
    {L"F120", L"Serval-640"},
    {L"F121", L"Serval-384"},

    // Bobcat Family
    {L"F035", L"Bobcat/XSW-640 - GigEVision"},
    {L"F036", L"Bobcat/XSW-640 - Analog"},
    {L"F037", L"Bobcat/XSW-640 - Camera Link"},

    // Lynx Family
    {L"F083", L"Lynx/XSL - Camera Link"},
    {L"F085", L"Lynx/XSL - GigEVision"},

    {L"616E", L"Unknown - GigEVision"}
};
