#pragma once

#include <mutex>
#include <map>

namespace rcf
{
// 第一个添加的为缺省值
template <class Ta, class Tb>
class Mapping
{
public:
    // 是否为空
    bool empty()
    {
        std::lock_guard<std::recursive_mutex> guard(m_lock);
        if (m_mapping.empty()) return true;
        else return false;
    }
    
    // 数量
    uint64_t size()
    {
        std::lock_guard<std::recursive_mutex> guard(m_lock);
        return m_mapping.size();
    }
    
    // 添加
    void add(const Ta &taObj, const Tb &tbObj, const bool b_default=false)
    {
        std::lock_guard<std::recursive_mutex> guard(m_lock);
        if (b_default)
        {
            m_taDefault = taObj;
            m_tbDefault = tbObj;
        }
        m_mapping[taObj] = tbObj;
    }
    
    // 查询
    Tb get(const Ta &taObj, const bool b_remove=false)
    {
        std::lock_guard<std::recursive_mutex> guard(m_lock);
        auto iter = m_mapping.find(taObj);
        if (m_mapping.end() == iter) return m_tbDefault;
        
        Tb tbObj = m_mapping[taObj];
        if (b_remove) m_mapping.erase(iter);
        return tbObj;
    }
    Tb operator [](const Ta &taObj)
    {
        return get(taObj);
    }
    Ta get(const Tb &tbObj, const bool bRemove=false)
    {
        std::lock_guard<std::recursive_mutex> guard(m_lock);
        auto iter = m_mapping.begin();
        for (; iter != m_mapping.end(); iter++)
        {
            if (tbObj == iter->second) break;
        }
        if (m_mapping.end() == iter) return m_taDefault;
        
        Ta taObj = iter->first;
        if (bRemove) m_mapping.erase(iter);
        return taObj;
    }
    Ta operator [](const Tb &tbObj)
    {
        return get(tbObj);
    }
    
    
private:
    std::recursive_mutex m_lock;
    std::map<Ta, Tb> m_mapping;
    Ta m_taDefault;
    Tb m_tbDefault;
};

}


