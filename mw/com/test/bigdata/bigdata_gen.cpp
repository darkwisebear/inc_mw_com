// *******************************************************************************
// Copyright (c) 2025 Contributors to the Eclipse Foundation
//
// See the NOTICE file(s) distributed with this work for additional
// information regarding copyright ownership.
//
// This program and the accompanying materials are made available under the
// terms of the Apache License Version 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0
//
// SPDX-License-Identifier: Apache-2.0
// *******************************************************************************

#include "platform/aas/mw/com/test/common_test_resources/big_datatype.h"

#include <cassert>

extern "C" {

::bmw::mw::com::test::BigDataProxy* mw_com_gen_ProxyWrapperClass_mw_com_test_BigData_create(
    const ::bmw::mw::com::test::BigDataProxy::HandleType& handle)
{
    if (auto result = ::bmw::mw::com::test::BigDataProxy::Create(handle); result.has_value())
    {
        return new ::bmw::mw::com::test::BigDataProxy{std::move(result).value()};
    }
    else
    {
        // Todo convert error and return that instead of a nullptr
        return nullptr;
    }
}

void mw_com_gen_ProxyWrapperClass_mw_com_test_BigData_delete(::bmw::mw::com::test::BigDataProxy* proxy)
{
    delete proxy;
}

::bmw::mw::com::impl::ProxyEvent<::bmw::mw::com::test::MapApiLanesStamped>*
mw_com_gen_ProxyWrapperClass_mw_com_test_BigData_map_api_lanes_stamped_get(
    ::bmw::mw::com::test::BigDataProxy* proxy) noexcept
{
    return &proxy->map_api_lanes_stamped_;
}

bool mw_com_gen_ProxyEvent_MapApiLanesStamped_get_new_sample(
    ::bmw::mw::com::impl::ProxyEvent<::bmw::mw::com::test::MapApiLanesStamped>& proxy_event,
    ::bmw::mw::com::impl::SamplePtr<::bmw::mw::com::test::MapApiLanesStamped>* sample_ptr) noexcept
{
    bool received = false;
    const auto result = proxy_event.GetNewSamples(
        [sample_ptr,
         &received](::bmw::mw::com::impl::SamplePtr<::bmw::mw::com::test::MapApiLanesStamped> sample_ptr_in) {
            assert(!received);
            // Use placement new to not delete garbage as the sample ptr is an uninitialized out pointer
            new (sample_ptr)::bmw::mw::com::impl::SamplePtr<::bmw::mw::com::test::MapApiLanesStamped>{
                std::move(sample_ptr_in)};
            received = true;
        },
        1);

    // If received is set but result is bad, we don't want to return a pointer. Therefore, delete the
    // already-received sample and return false
    if (received && !result.has_value())
    {
        delete sample_ptr;
        return false;
    }
    else
    {
        return received;
    }
}

std::uint32_t mw_com_gen_MapApiLanesStamped_get_size() noexcept
{
    return sizeof(::bmw::mw::com::test::MapApiLanesStamped);
}

const ::bmw::mw::com::test::MapApiLanesStamped* mw_com_gen_SamplePtr_MapApiLanesStamped_get(
    const ::bmw::mw::com::impl::SamplePtr<::bmw::mw::com::test::MapApiLanesStamped>* sample_ptr) noexcept
{
    return sample_ptr->Get();
}

void mw_com_gen_SamplePtr_MapApiLanesStamped_delete(
    ::bmw::mw::com::impl::SamplePtr<::bmw::mw::com::test::MapApiLanesStamped>* sample_ptr)
{
    sample_ptr->~SamplePtr<::bmw::mw::com::test::MapApiLanesStamped>();
}
}

extern "C" {
::bmw::mw::com::test::BigDataSkeleton* mw_com_gen_SkeletonWrapperClass_mw_com_test_BigData_create(
    const ::bmw::mw::com::InstanceSpecifier& instance_specifier)
{

    if (auto result = ::bmw::mw::com::test::BigDataSkeleton::Create(instance_specifier); result.has_value())
    {
        return new ::bmw::mw::com::test::BigDataSkeleton{std::move(result).value()};
    }
    else
    {
        // Todo convert error and return that instead of a nullptr
        return nullptr;
    }
}

bmw::mw::com::impl::SkeletonEvent<::bmw::mw::com::test::MapApiLanesStamped>*
mw_com_gen_SkeletonWrapperClass_mw_com_test_BigData_map_api_lanes_stamped_get(
    ::bmw::mw::com::test::BigDataSkeleton* skeleton)
{
    return &(skeleton->map_api_lanes_stamped_);
}

void mw_com_gen_SkeletonWrapperClass_mw_com_test_BigData_delete(::bmw::mw::com::test::BigDataSkeleton* skeleton)
{
    delete skeleton;
}

bool mw_com_gen_SkeletonWrapperClass_mw_com_test_BigData_offer(::bmw::mw::com::test::BigDataSkeleton* skeleton)
{
    if (skeleton->OfferService().has_value())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void mw_com_gen_SkeletonWrapperClass_mw_com_test_BigData_stop_offer(::bmw::mw::com::test::BigDataSkeleton* skeleton)
{
    skeleton->StopOfferService();
}

bool mw_com_gen_SkeletonWrapperClass_mw_com_test_BigData_map_api_lanes_stamped_send(
    bmw::mw::com::impl::SkeletonEvent<::bmw::mw::com::test::MapApiLanesStamped>* event,
    bmw::mw::com::test::MapApiLanesStamped* data_stamped)
{
    if (event->Send(std::move(*data_stamped)).has_value())
    {
        return true;
    }
    else
    {
        return false;
    }
}
}
