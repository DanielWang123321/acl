//
// Created by shuxin ����zheng on 2023/7/19.
//

#pragma once

#include <vector>
#include "c++_patch.h"
#include "redis_object.h"

namespace pkv {

class redis_coder {
public:
    explicit redis_coder(size_t cache_max = 10000);
    ~redis_coder();

    const char* update(const char* data, size_t& len);

    NODISCARD const std::vector<redis_object*>& get_objects() const {
        return objs_;
    }

    NODISCARD redis_object* get_curr() const {
        return curr_;
    }

    void clear();

public:
    NODISCARD redis_object& create_object();

    bool to_string(std::string& out) const;

private:
    std::vector<redis_object*> objs_;
    std::vector<redis_object*> cache_;
    size_t cache_max_;
    redis_object* curr_;
};

bool test_redis_parse(const char* filepath);
bool test_redis_parse_once(const char* filepath);
bool test_redis_parse_stream(const char* filepath);

bool test_redis_build();

} // namespace pkv
