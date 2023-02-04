#ifndef _UTILS_H_
#define _UTILS_H_

#define INSTANTIATE_STRUCT_TEMPLATES(StructName)        template struct StructName<uint8_t>;\
                                                        template struct StructName<int8_t>;\
                                                        template struct StructName<uint16_t>;\
                                                        template struct StructName<int16_t>;\
                                                        template struct StructName<uint32_t>;\
                                                        template struct StructName<int32_t>;\
                                                        template struct StructName<uint64_t>;\
                                                        template struct StructName<int64_t>;


#define INSTANTIATE_CLASS_TEMPLATES(ClassName)          template class ClassName<uint8_t>;\
                                                        template class ClassName<int8_t>;\
                                                        template class ClassName<uint16_t>;\
                                                        template class ClassName<int16_t>;\
                                                        template class ClassName<uint32_t>;\
                                                        template class ClassName<int32_t>;\
                                                        template class ClassName<uint64_t>;\
                                                        template class ClassName<int64_t>;

#endif // _UTILS_H_